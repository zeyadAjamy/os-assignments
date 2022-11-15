if [ ! -d ../week01 ]; then
    mkdir week01
fi
if [ ! -d week10 ]; then
    mkdir ../week10
fi
if [ -f _ex2.txt ]; then
    rm _ex2.txt
fi
if [ -f ex2.txt ]; then
    rm ex2.txt
fi
if [ -f ../week01/file.txt ]; then
    rm ../week01/file.txt
fi

touch ../week01/file.txt
echo "Some content" > ../week01/file.txt

# link file.txt to _ex2.txt
link ../week01/file.txt _ex2.txt

# get the inode number of _ex2.txt
inode=$(ls -i ../week01/file.txt | cut -d ' ' -f 1)

# find all the links to the inode number
echo "The links to the inode number $inode in the current directory are: " >> ex2.txt
find .. -inum $inode >> ex2.txt

# remove the link
echo "The removed links are " >> ex2.txt
find . -inum $inode -exec rm {} \; -print >> ex2.txt
