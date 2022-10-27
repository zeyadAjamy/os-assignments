# Compile and run the program in the background (./ex2 &) and
# run ’vmstat 1 ’ at the same time.

# Compile the program
gcc ex2.c -o ex2

# Run the program in the background
./ex2 &

# Run ’vmstat 1 ’
vmstat 1
