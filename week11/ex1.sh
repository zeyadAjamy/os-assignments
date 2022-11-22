# Create lofs.img which is 50 Mg size 
sudo dd if=/dev/zero of=lofs.img bs=1M count=50

# store the next empty loop device
LOOPDEV=$(sudo losetup -f)

sudo losetup $LOOPDEV lofs.img
sudo mkfs.ext4 $LOOPDEV

# If the lofsdisk is already mounted, unmount it
if mount | grep lofsdisk > /dev/null; then
    # get the loop device
    LOOPDEV=$(mount | grep lofsdisk | awk '{print $1}')
    # unmount the loop device
    sudo umount $LOOPDEV
    sudo umount lofsdisk

fi

# Remove the lofsdisk directory if it exists
sudo rm -rf lofsdisk
sudo fsck.ext4 -f $LOOPDEV

# mount the loop device
mkdir lofsdisk
sudo mount $LOOPDEV lofsdisk
