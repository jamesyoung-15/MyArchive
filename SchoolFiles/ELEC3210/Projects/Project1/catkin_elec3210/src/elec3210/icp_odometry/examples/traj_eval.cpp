#include <iostream>
#include <fstream>
#include "global_definition.h"
#include <vector>
#include <Eigen/Dense>
#include <numeric>

struct Pose {
    double timestamp;
    Eigen::Matrix4d pose;
};

std::vector<Pose> load_data(const std::string &filename) {
    std::vector<Pose> data;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Pose p;
        iss >> p.timestamp;
        p.pose = Eigen::Matrix4d::Identity();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                iss >> p.pose(i, j);
            }
        }
        data.push_back(p);
    }
    return data;
}

int main() {
    std::vector<Pose> est = load_data(WORK_SPACE_PATH + "/../dataset/est_trajectory.txt"); // WORK_SPACE_PATH is defined in "global_definition.h
    std::vector<Pose> gt = load_data(WORK_SPACE_PATH + "/../dataset/true_trajectory.txt");

    std::vector<double> trans_errors;
    std::vector<double> rot_errors;

    for (const Pose &e : est) {
        auto it = std::lower_bound(gt.begin(), gt.end(), e.timestamp, [](const Pose &p, double t) { return p.timestamp < t; });
        if (it != gt.end() && std::abs(it->timestamp - e.timestamp) < 0.1) {
            Eigen::Vector3d trans_error = e.pose.block<3, 1>(0, 3) - it->pose.block<3, 1>(0, 3);
            trans_errors.push_back(trans_error.norm());

            Eigen::Matrix3d rot_diff = e.pose.block<3, 3>(0, 0).transpose() * it->pose.block<3, 3>(0, 0);
            double cos_angle = (rot_diff.trace() - 1) / 2;
            if (cos_angle > 1) cos_angle = 1;
            if (cos_angle < -1) cos_angle = -1;
            double rot_error = std::acos(cos_angle);
            rot_errors.push_back(rot_error);
        }
    }

    double mean_trans_error = std::accumulate(trans_errors.begin(), trans_errors.end(), 0.0) / trans_errors.size();
    double mean_rot_error = std::accumulate(rot_errors.begin(), rot_errors.end(), 0.0) / rot_errors.size();

    double sq_sum_trans = std::inner_product(trans_errors.begin(), trans_errors.end(), trans_errors.begin(), 0.0);
    double std_dev_trans = std::sqrt(sq_sum_trans / trans_errors.size() - mean_trans_error * mean_trans_error);

    double sq_sum_rot = std::inner_product(rot_errors.begin(), rot_errors.end(), rot_errors.begin(), 0.0);
    double std_dev_rot = std::sqrt(sq_sum_rot / rot_errors.size() - mean_rot_error * mean_rot_error);

    std::cout << "Mean translation error: " << mean_trans_error << std::endl;
    std::cout << "Standard deviation of translation error: " << std_dev_trans << std::endl;
    std::cout << "Mean rotation error: " << mean_rot_error * 180 / M_PI << std::endl;
    std::cout << "Standard deviation of rotation error: " << std_dev_rot * 180 / M_PI << std::endl;

    return 0;
}