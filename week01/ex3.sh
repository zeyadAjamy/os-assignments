date_wait(){
	date
	sleep 3
}

date_wait
mkdir Root && cd Root
date_wait

touch root.txt
cd / && ls -t -r >  ~/week01/Root/root.txt 
date_wait

cd ~/week01/
mkdir Home && cd Home
date_wait

touch home.txt
cd ~ && ls -t -r > ~/week01/Home/home.txt

exit

