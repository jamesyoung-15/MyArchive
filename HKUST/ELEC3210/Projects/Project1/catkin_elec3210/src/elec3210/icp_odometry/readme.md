# ELEC3210 Project #1 By Young, James Yang (20740589)


## About Assignment
[Assignment 1 Details](./ELEC3210_Assignment1.pdf)
- Part 1: Implement own ICP 
    -  implemented own ICP in `src/myicp.cpp` and `include/myicp.h`, replaced example `icp_registration` with own working one, toy example gives close to ground truth

- Part 2: Odometry Estimation w/ ICP
    - odometry estimation implemented in `odometry.cpp`

- Part 3: Odometry Estimation w/ ICP using Keyframes
    - odometry estimation implemented in `odometry.cpp`, not optimized well runs slower than part 2

- Part 4: Odometry Estimation w/ ICP using Local Map
    - odometry estimation implemented in `odometry.cpp`, does not work well

For testing part 1 I put my own implementation output to `transform_output.txt` under the dataset folder so that I can compare with the ground truth `true_t.txt`.

For testing part 2-4, can change `odometry.yaml` under configs and change the `test_part` to 2,3, or 4 corresponding to above parts, defaults to 2 as it works best for me. The trajectory is outputted to `est_trajectory.txt`.