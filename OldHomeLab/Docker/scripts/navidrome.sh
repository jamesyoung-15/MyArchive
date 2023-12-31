docker run -d \
   --name navidrome \
   --restart=unless-stopped \
   --user $(id -u):$(id -g) \
   -v /new-pool/jellyfin/media/music:/music \
   -v /new-pool/jellyfin/media/navidrome-data:/data \
   -p 4533:4533 \
   -e ND_LOGLEVEL=info \
   deluan/navidrome:latest
