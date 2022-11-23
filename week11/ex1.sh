# Create lofs.img which is 50 Mg size 
sudo dd if=/dev/zero of=lofs.img bs=1M count=50

# store the next empty loop device
LOOPDEV=$(sudo losetup -f)

sudo losetup $LOOPDEV lofs.img
sudo mkfs.ntfs $LOOPDEV

# Remove the lofsdisk directory if it exists
sudo umount lofsdisk
sudo rm -rf lofsdisk

# mount the loop device
mkdir lofsdisk
sudo mount $LOOPDEV lofsdisk
