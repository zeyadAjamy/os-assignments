gcc ex3.c -o ex3 -pthread

for i in 1 2 4 10 100 
do
    (time ./ex3 10000000 $i ) 2>> ex3.txt
done    
