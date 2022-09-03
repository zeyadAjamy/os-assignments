# some commands
pwd > /dev/null
ls | sort > /dev/null

# as bash disables the history, we can turn it on by
HISTFILE=~/.bash_history
set -o history

# create the output file -ex2.txt
touch ex2.txt

# print the history into the ex2.txt
history > ex2.txt

exit
