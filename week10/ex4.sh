# If the dir doesnot exists remove
if [ -d tmp ]; then
    rm -r tmp
fi

mkdir tmp

touch tmp/file1 tmp/file2

# create a hard link link1.txt to file1.txt
ln tmp/file1 tmp/link1

gcc -o ex4 ex4.c

# Run the program
./ex4

# Remove the binary
rm ex4