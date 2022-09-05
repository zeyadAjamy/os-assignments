date_wait(){
	date
	sleep 3
}

# Remove the Root and Home folders if exist
cd ~/week01/
rm -r -f Root Home

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
cat ~/week01/Root/root.txt && cat ~/week01/Home/home.txt
ls ~/week01/Root && ls ~/week01/Home 

exit

