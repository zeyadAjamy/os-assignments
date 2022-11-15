if [ -d tmp ]; then
    rm -rf tmp
fi
mkdir tmp

touch tmp/file1.txt tmp/file2.txt

# create a hard link link1.txt to file1.txt
ln tmp/file1.txt tmp/link1.txt
