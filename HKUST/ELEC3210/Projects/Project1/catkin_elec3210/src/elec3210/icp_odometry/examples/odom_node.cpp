#include "odometry.h"
#include <thread>
#include "parameters.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "icp_odometry");
    ros::NodeHandle n("~");
    params::readParameters(n);

    OdomICP odom(n);
    std::thread odomThread(&OdomICP::run, &odom);
    ros::spin();

    return 0;
}