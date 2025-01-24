/**
** Created by Zhijian QIAO.
** UAV Group, Hong Kong University of Science and Technology
** email: zqiaoac@connect.ust.hk
**/

#ifndef SRC_PARAMETERS_H
#define SRC_PARAMETERS_H

#include <ros/ros.h>

namespace params {
    extern double max_distance;
    extern int max_iterations;
    extern int test_part; // my modification

    void readParameters(const ros::NodeHandle &nh);
}

#endif //SRC_PARAMETERS_H
