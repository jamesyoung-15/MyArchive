/**
** Created by Zhijian QIAO.
** UAV Group, Hong Kong University of Science and Technology
** email: zqiaoac@connect.ust.hk
**/

#include "parameters.h"

namespace params{
    // icp parameters
    double max_distance = 1.0;
    int max_iterations = 100;

    int test_part = 2; // my modification

    void readParameters(const ros::NodeHandle& nh){
        std::cout << "Reading parameters..." << std::endl;
        nh.getParam("/icp/max_iterations", max_iterations);
        std::cout << "max_iterations: " << max_iterations << std::endl;
        nh.getParam("/icp/max_distance", max_distance);
        std::cout << "max_distance: " << max_distance << std::endl;

        // my modification
        nh.getParam("/icp/test_part", test_part); 
            // part 3 is keyframe
            if(test_part==3)
                std::cout << "test_part= " << test_part << ": means Scan-to-KeyFrame Odometry selected" << std::endl;
            else if(test_part == 4)
                std::cout << "test_part= " << test_part << ": means Scan-to-Map Odometry selected" << std::endl;
            // default to scan2scan
            else
                std::cout << "test_part= " << test_part << ": means Scan-to-Scan Odometry selected" << std::endl;
    }
}
