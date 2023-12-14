#ifndef MYICP_H
#define MYICP_H

#include "parameters.h"
#include <pcl/registration/icp.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

/* Correspondence, the pair of source and target */
struct correspondencePoint{
    pcl::PointXYZ sourcePoint;
    pcl::PointXYZ targetPoint;
    correspondencePoint(pcl::PointXYZ source, pcl::PointXYZ target){
        sourcePoint = source; 
        targetPoint = target;
    };
};
/* Store distances to compute error, taken from online https://github.com/zjudmd1015/icp/blob/master/icp.cpp */
struct{
    std::vector<float> distances;
} neighborInfo;

class MY_ICP{
    public:
        /**
         * @brief Constructor for own ICP
         * 
         * @param maxIterations defaults to odometry.yaml config
         * @param maxDistance defaults to odometry.yaml config
         */
        MY_ICP(int maxIterations=params::max_iterations, double maxDistance=params::max_distance, double transformationEpsilon=1e-6);
        ~MY_ICP(){};

        /**
         * @brief Runs the ICP algorithm, refer L5 notes
         * 
         */
        void computeICP();

        /**
         * @brief Compute transformation matrix using steps from Lecture 5
         * @return 4x4 transformation matrix
         * 
         * Steps:
         * 1. calculate SVD
         *      i. compute mean
         *      ii. compute mean-reduced coordinate
         *      iii. get covariance matrix
         * 2. calculate rotation matrix
         * 3. calculate translation matrix
         * 4. combine to create transformation matrix
         * 
         */
        Eigen::Matrix4d computeTransformationMatrix();

        // Setter Functions

        /**
         * @brief Set the Input Source point cloud
         * 
         * @param sourcePointCloud input pcl source
         */
        void setInputSource(pcl::PointCloud<pcl::PointXYZ>::Ptr sourcePointCloud);

        /**
         * @brief Set the Input Target point cloud
         * 
         * @param targetPointCloud input pcl target
         */
        void setInputTarget(pcl::PointCloud<pcl::PointXYZ>::Ptr targetPointCloud);

        /**
         * @brief Store initial guess to final transformation variable
         * 
         * @param init_guess Initial transformation matrix for ICP
         */
        void setInitialGuess(Eigen::Matrix4d init_guess);

        // Getter functions

        /**
         * @brief Gets the Final Transformation matrix
         * @return 4x4 transformation matrix
         */
        Eigen::Matrix4d getFinalTransformation() const{
            return finalTransformation;
        }


    private:
        // tweakable performance variables
        int maxIterations;
        double maxDistance;
        double transformationEpsilon;
        // point cloud variables
        pcl::PointCloud<pcl::PointXYZ>::Ptr sourcePointCloud;
        pcl::PointCloud<pcl::PointXYZ>::Ptr targetPointCloud;
        pcl::PointCloud<pcl::PointXYZ>::Ptr transformedSourcePointCloud;
        // vector of correspondence points (ie. the pair of source and target points)
        std::vector<correspondencePoint>correspondencePoints; 
        // final transformed 4x4 matrix
        Eigen::Matrix4d finalTransformation;
};


#endif