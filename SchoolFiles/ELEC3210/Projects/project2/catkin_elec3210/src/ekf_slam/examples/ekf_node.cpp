#include "ekf_slam.h"
#include <thread>

int main(int argc, char **argv) {
    ros::init(argc, argv, "ekf_node");
    ros::NodeHandle n("~");

    EKFSLAM ekfslam(n);
    std::thread slamThread(&EKFSLAM::run, &ekfslam);
    ros::spin();

    return 0;
}