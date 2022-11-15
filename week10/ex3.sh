if [ -f _ex3.txt ]; then 
    rm _ex3.txt
fi

touch _ex3.txt

# Remove the excutable permission from the file for all
echo "The file _ex3.txt has no excutable permission for all" >> ex3.txt
chmod a-x _ex3.txt
ls -l _ex3.txt >> ex3.txt

# Grant all permissions for the owner and others
chmod u=rwx _ex3.txt
chmod o=rwx _ex3.txt
echo "The file _ex3.txt has all permissions for the owner and others" >> ex3.txt
ls -l _ex3.txt >> ex3.txt

# Grant all the user permissions for the group
chmod g=u _ex3.txt
echo "The file _ex3.txt has all the user permissions for the group" >> ex3.txt
ls -l _ex3.txt >> ex3.txt


# Echo the answer to the ex3.txt
echo "660 means: both the owner and the group have read and write permissions without the excution permission, but others have no permissions" >> ex3.txt
echo "775 means: the owner and the group have read, write and excute permissions, but others have read and excute permissions without the write permission" >> ex3.txt
echo "777 means: owner, group, and others have read, write and excute permissions" >> ex3.txt