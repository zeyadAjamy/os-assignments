# Create ex.1.txt file
touch ex1.txt

# Go to usr/bin dir
cd /usr/bin

# Search, sort, and print the last 5 lines in ex1.txt
ls | grep gcc | sort -r | tail -n 5 > ~/week01/ex1.txt

exit
