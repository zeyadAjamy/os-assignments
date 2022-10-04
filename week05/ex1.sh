gcc publisher.c -o publisher
gcc subscriber.c -o subscriber

argv=3

# the argv should be betweem 1 and 3 
if [ $argv -ge 1 ] && [ $argv -le 3 ]; then
    gnome-terminal -- ./publisher $argv
    for ((i=0; i<$argv; i++))
    do
        gnome-terminal -- ./subscriber
    done
else
    echo "The argv is not between 1 and 3"
fi