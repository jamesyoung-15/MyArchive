# Get Docker Ubuntu 20.04 VNC image
FROM dorowu/ubuntu-desktop-lxde-vnc:focal

# install ros noetic
RUN wget -q -O - https://dl.google.com/linux/linux_signing_key.pub | apt-key add -
RUN apt-get update -q && \
    apt-get upgrade -yq && \
    DEBIAN_FRONTEND=noninteractive apt-get install -yq wget curl git build-essential vim sudo lsb-release locales bash-completion tzdata gosu && \
    rm -rf /var/lib/apt/lists/*
RUN curl -k https://raw.githubusercontent.com/ros/rosdistro/master/ros.key | apt-key add -
RUN echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list
RUN apt-get update && apt-get install -y ros-noetic-desktop-full

# Install additional ROS tools and dependencies
RUN apt-get install -y python3-rosdep


# Initialize rosdep
RUN rosdep init
RUN rosdep update


RUN apt-get install -y python3-rosinstall python3-rosinstall-generator python3-wstool build-essential python3-vcstool
RUN apt-get install -y python3-catkin-tools python3-osrf-pycommon

# Set up environment variables
RUN echo "export ROS_IP=127.0.0.1" >> ~/.bashrc
RUN echo "export ROS_MASTER_URI=http://\$ROS_IP:11311" >> ~/.bashrc
RUN echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc