if [ -f _ex1_1.txt ] | [ -f _ex1_2.txt ] | [ -f ex1.txt ]; then
    rm _ex1_1.txt
    rm _ex1_2.txt
    rm ex1.txt
fi

# Create the required files
touch _ex1.txt _ex1_1.txt ex1.txt

# Append "Zeyad Alagamy" to _ex1.txt
echo "Zeyad Alagamy" >> _ex1.txt

# Link _ex1_1.txt to _ex1_2.txt
ln _ex1_1.txt _ex1_2.txt

# Append "Zeyad Alagamy" to _ex1_1.txt
echo "Zeyad Alagamy" >> _ex1_1.txt # "Zeyad Alagamy" is appended to _ex1.txt and _ex1_1.txt

# Append the i-node number to ex1.txt
ls -i _ex1.txt >> ex1.txt
ls -i _ex1_1.txt >> ex1.txt
ls -i _ex1_2.txt >> ex1.txt