gcc ex2.c -o ex2.out -static -static-libgcc -static-libstdc++
./ex2.out > ex2.txt

cd ./lofsdisk
echo "Zeyad" > file1.txt
echo "Alagamy" > file2.txt 

sudo rm -rf bin
sudo rm -rf lib
sudo rm -rf lib64
mkdir bin lib lib64 lib/x86_64-linux-gnu

# Add bash, cat, echo, ls commands to the LOFS. Add their shared libraries too, otherwise they won’t work.
sudo cp /bin/bash bin/
sudo cp /bin/cat bin/
sudo cp /bin/echo bin/
sudo cp /bin/ls bin/

# copy the shared libraries directories to the LOFS
for i in $(ldd /bin/bash | grep -o '/.* '); do sudo cp $i lib/x86_64-linux-gnu; done
for i in $(ldd /bin/cat | grep -o '/.* '); do sudo cp $i lib/x86_64-linux-gnu; done
for i in $(ldd /bin/echo | grep -o '/.* '); do sudo cp $i lib/x86_64-linux-gnu; done
for i in $(ldd /bin/ls | grep -o '/.* '); do sudo cp $i lib/x86_64-linux-gnu; done
for i in $(ldd /bin/bash | grep -o '/.* '); do sudo cp $i lib64/; done
for i in $(ldd /bin/cat | grep -o '/.* '); do sudo cp $i lib64/; done
for i in $(ldd /bin/echo | grep -o '/.* '); do sudo cp $i lib64/; done
for i in $(ldd /bin/ls | grep -o '/.* '); do sudo cp $i lib64/; done


cd ..
echo "Output with lofsdisk as a root " > ex2.txt
sudo chroot lofsdisk ./ex2.out >> ex2.txt
echo "" >> ex2.txt
echo "Output without lofsdisk as a root" >> ex2.txt
./ex2.out >> ex2.txt
