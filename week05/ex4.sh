# compile
gcc -o ex4 ex4.c -pthread

# run
for i in 1 2 4 10 100
do
    (time ./ex4 10000000 $i ) 2>> ex4.txt
done