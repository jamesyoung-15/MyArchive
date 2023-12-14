
# Setup Instructions

``` bash
docker network create ros
```
``` bash
docker pull theasp/novnc:latest &&
```
``` bash
docker run -d --rm --net=ros \
   --env="DISPLAY_WIDTH=3000" --env="DISPLAY_HEIGHT=1800" --env="RUN_XTERM=no" \
   --name=novnc -p=8080:8080 \
   theasp/novnc:latest && 
```

``` bash
docker build -t my-ros-noetic-image .
```