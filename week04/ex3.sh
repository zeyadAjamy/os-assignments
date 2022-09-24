gcc -o ex3 ex3.c
./ex3 3 &

# print the pstree for the previous process one every second
for i in {0..2}; do 
    pstree $!
    sleep 5
done

# wait for the the previous process to finish
wait $! 
echo "First trail with n=3 is done!. Now n = 5:"
./ex3 5 &
for i in {0..4}; do
    pstree $!
    sleep 5
done