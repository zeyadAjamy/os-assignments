# some commands
pwd > /dev/null
ls | sort > /dev/null

# as bash disables the history, we can turn it on by
# got from stackexchange, please check https://unix.stackexchange.com/questions/5684/history-command-inside-bash-script
HISTFILE=~/.bash_history
set -o history

# create the output file -ex2.txt
touch ex2.txt

# print the history into the ex2.txt
history > ex2.txt

exit
