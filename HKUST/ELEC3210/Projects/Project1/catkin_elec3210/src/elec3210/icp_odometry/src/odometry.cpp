#include "odometry.h"
#include <sensor_msgs/PointCloud2.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/filters/filter.h>
#include <pcl/common/transforms.h>
#include <pcl/filters/passthrough.h>
#include "global_definition.h"
#include "parameters.h"
#include "chrono"
#include "thread"

using namespace std;
using namespace Eigen;


OdomICP::~OdomICP() {}

OdomICP::OdomICP(ros::NodeHandle &nh):
        nh_(nh) {
//    initialize variables here
    Twb = Eigen::Matrix4d::Identity(); // initial pose
    laserCloudIn.reset(new pcl::PointCloud<pcl::PointXYZ>);
    refCloud.reset(new pcl::PointCloud<pcl::PointXYZ>);

    // my modifications:
    localMapPointCloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
    Twb_prev = Eigen::Matrix4d::Identity(); // transformation from body to world (previous)
    deltaT_pred = Eigen::Matrix4d::Identity();; // predicted transformation from previous to current
    Twk = Eigen::Matrix4d::Identity();; // transformation from keyframe to world
    // Twb_gt = Eigen::Matrix4d::Identity();; // transformation from body to world (ground truth)

//    initialze downsample filter here
    const double scan_leaf_size = 0.5, map_leaf_size = 0.1;
    dsFilterScan.setLeafSize(scan_leaf_size, scan_leaf_size, scan_leaf_size);
    dsFilterMap.setLeafSize(map_leaf_size, map_leaf_size, map_leaf_size);

//    initialize ros publisher
    lidar_sub = nh_.subscribe("/velodyne_points", 1, &OdomICP::cloudHandler, this);
    odom_pub = nh_.advertise<nav_msgs::Odometry>("icp_odometry", 1);
    path_pub = nh_.advertise<nav_msgs::Path>("icp_path", 1);
    scan_pub = nh_.advertise<sensor_msgs::PointCloud2>("current_scan", 1);
    map_pub = nh_.advertise<sensor_msgs::PointCloud2>("cloud_map", 1);

   traj_file.open(WORK_SPACE_PATH + "/../dataset/est_trajectory.txt");
    std::cout << "Odometry ICP initialized" << std::endl;
}

void OdomICP::run() {
    ros::Rate rate(1000);
    while (ros::ok()){
        if (cloudQueue.empty()){
            rate.sleep();
            continue;
        }

        cloudQueueMutex.lock();
        cloudHeader = cloudQueue.front().first;
        laserCloudIn = parseCloud(cloudQueue.front().second);
        cloudQueue.pop();
        cloudQueueMutex.unlock();

        std::chrono::time_point<std::chrono::system_clock> start;
        if (firstFrame){
            firstFrame = false;
            // reset variables
            Twb = Eigen::Matrix4d::Identity();
            *refCloud = *laserCloudIn;
            Twb_prev = Eigen::Matrix4d::Identity(); // transformation from body to world (previous)
            deltaT_pred = Eigen::Matrix4d::Identity();; // predicted transformation from previous to current
            Twk = Eigen::Matrix4d::Identity();; // transformation from keyframe to world
            
            // Part 3: Keyframe using timestamp
            start = std::chrono::high_resolution_clock::now();
            continue;
        }

        timer.tic();
        /* Odometry estimation */
        // 1. preprocess: downsample
        // Note: taken from pcl downsampling documentation: https://pcl.readthedocs.io/projects/tutorials/en/latest/voxel_grid.html
        
        // init pointer variables to store filtered point cloud
        pcl::PointCloud<pcl::PointXYZ>::Ptr laserCloudInFiltered(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::PointCloud<pcl::PointXYZ>::Ptr refCloudFiltered(new pcl::PointCloud<pcl::PointXYZ>);
        // filter the pointclouds with VoxelGrid filter
        dsFilterScan.setInputCloud(laserCloudIn); // input
        dsFilterScan.filter(*laserCloudInFiltered); // store output
        dsFilterMap.setInputCloud(refCloud); // input
        dsFilterMap.filter(*refCloudFiltered); // store output

        // 2. icp
        // use filtered point cloud and apply delta prediction
        Twb = icp_registration(laserCloudInFiltered, refCloudFiltered, deltaT_pred*Twb);

        // 3. update pose
        // from ChatGPT: If Twb represents a transformation from frame a to frame b, then take the inverse of Twb to get previous transformation from b back to frame a.
        // To use the previous transformation and initial pose to predict the transformation from the previous frame to the current frame, you can perform the following steps:
        // Obtain the transformation matrix from the initial frame to the previous frame (let's call it T_initial_previous).
        // Obtain the transformation matrix from the initial frame to the current frame (let's call it T_initial_current). This can be done by applying the predicted transformation to the initial frame.
        // Compute the transformation matrix from the previous frame to the current frame (let's call it T_previous_current) by multiplying the inverse of T_initial_previous with T_initial_current.

        // calculate Twb previous by taking inverse
        Twb_prev = Twb.inverse();
        // predict transfromation of previous to current by multiplying previous to inital current
        deltaT_pred = Twb_prev * Twb;
        // TODO: rotate around axis z, need to do this as my pathing wasn't right
        // Eigen::Matrix3d rotation = Eigen::Matrix3d::Identity();
        // https://en.wikipedia.org/wiki/Rotation_matrix


        // timestamp method instead of overlap
        std::chrono::milliseconds threshold(10);

         // 4. update reference cloud

        // // Part 3 Keyframe by timestamp
        if(params::test_part == 3){
            // check if time elapsed passes threshold, if it is update 
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            if(elapsed>=threshold){
                // update keyframe, reset start timer
                pcl::transformPointCloud(*laserCloudIn,*refCloud, Twb.cast<float>());
                start = std::chrono::high_resolution_clock::now();
            }
        }
        // // Part 4 Local Map
        else if(params::test_part == 4){
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            if(elapsed>=threshold){
                // update keyframe
                pcl::transformPointCloud(*laserCloudIn,*refCloud, Twb.cast<float>());
                // TODO
                // ?? update local map, not sure how to do this, try by building with new keyframes, also adds too many points
                *localMapPointCloud += *laserCloudIn;
                // filter local map
                filterLocalMap();
                // reset timer
                start = std::chrono::high_resolution_clock::now();
            }
        }
        // // Part 2 scan to scan default
        else{
            pcl::transformPointCloud(*laserCloudIn,*refCloud, Twb.cast<float>());
        }
        timer.toc();

        // 5. publish result
        publishResult();
        rate.sleep();
    }
}

// for part 4
void OdomICP::filterLocalMap(){
    // https://pcl.readthedocs.io/projects/tutorials/en/latest/voxel_grid.html
    // pcl::VoxelGrid<pcl::PointXYZ> sor;
    // sor.setInputCloud(localMapPointCloud);
    // sor.setLeafSize (0.01f, 0.01f, 0.01f);
    // sor.filter(*localMapPointCloud);
    
    // try passthrough
    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud(localMapPointCloud);
    pass.setFilterFieldName ("z");
    pass.filter (*localMapPointCloud);
}

void OdomICP::cloudHandler(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){
    cloudQueueMutex.lock();
    std_msgs::Header cloudHeader = laserCloudMsg->header;
    cloudHeader.stamp = ros::Time::now();
    cloudQueue.push(std::make_pair(cloudHeader, laserCloudMsg));
    cloudQueueMutex.unlock();
}

pcl::PointCloud<pcl::PointXYZ>::Ptr OdomICP::parseCloud(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloudTmp(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromROSMsg(*laserCloudMsg, *cloudTmp);
    // Remove Nan points
    std::vector<int> indices;
    pcl::removeNaNFromPointCloud(*cloudTmp, *cloudTmp, indices);
    return cloudTmp;
}

void OdomICP::publishResult() {
//    publish odom
    nav_msgs::Odometry odom;
    odom.header.frame_id = "map";
    odom.child_frame_id = "base_link";
    odom.header.stamp = cloudHeader.stamp;
    odom.pose.pose.position.x = Twb(0,3);
    odom.pose.pose.position.y = Twb(1,3);
    odom.pose.pose.position.z = Twb(2,3);
    Eigen::Quaterniond q(Twb.block<3,3>(0,0));
    q.normalize();
    odom.pose.pose.orientation.x = q.x();
    odom.pose.pose.orientation.y = q.y();
    odom.pose.pose.orientation.z = q.z();
    odom.pose.pose.orientation.w = q.w();
    odom_pub.publish(odom);

//    publish path
    path.header.frame_id = "map";
    path.header.stamp = cloudHeader.stamp;
    geometry_msgs::PoseStamped pose;
    pose.header = odom.header;
    pose.pose = odom.pose.pose;
    path.poses.push_back(pose);
    path_pub.publish(path);

//    publish map
    sensor_msgs::PointCloud2 mapMsg;
    pcl::toROSMsg(*refCloud, mapMsg);
    mapMsg.header.frame_id = "map";
    mapMsg.header.stamp = cloudHeader.stamp;
    map_pub.publish(mapMsg);

//    publish laser
    sensor_msgs::PointCloud2 laserMsg;
    pcl::PointCloud<pcl::PointXYZ>::Ptr laserTransformed(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::transformPointCloud(*laserCloudIn, *laserTransformed, Twb.cast<float>());
    pcl::toROSMsg(*laserTransformed, laserMsg);
    laserMsg.header.frame_id = "map";
    laserMsg.header.stamp = cloudHeader.stamp;
    scan_pub.publish(laserMsg);

    Eigen::Vector3d rpy = q.toRotationMatrix().eulerAngles(0, 1, 2) * 180 / M_PI;
    std::cout << "x: " << Twb(0,3) << " y: " << Twb(1,3) << " z: " << Twb(2,3) << " roll: " << rpy(0) << " pitch: " << rpy(1) << " yaw: " << rpy(2)
    << " time: " << timer.duration_ms() << " ms" << std::endl;
   traj_file << std::fixed << cloudHeader.stamp.toSec() << " " << Twb(0,0) << " " << Twb(0,1) << " " << Twb(0,2) << " " << Twb(0,3) << " "
   << Twb(1,0) << " " << Twb(1,1) << " " << Twb(1,2) << " " << Twb(1,3) << " "
   << Twb(2,0) << " " << Twb(2,1) << " " << Twb(2,2) << " " << Twb(2,3) << std::endl;
}

