#!/bin/bash
# not used anymore use docker-compose one instead
docker run -d \
 --name jellyfin \
 --user 1000:1000 \
 --group-add=109 \
 --device=/dev/dri:/dev/dri \
 --net=host \
 --volume /new-pool/jellyfin/config:/config \
 --volume /new-pool/jellyfin/cache:/cache \
 --mount type=bind,source=/new-pool/jellyfin/media,target=/media \
 --restart=unless-stopped \
 jellyfin/jellyfin
