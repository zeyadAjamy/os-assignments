#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd;
    char * myfifo = "/tmp/ex1";
    char buf[1024];
    int subs = 0;

    subs = atoi(argv[1]);

    printf("I am a publisher with %d subscribers\n", subs);

    if (subs < 1 || subs > 3) {
        printf("Error: Invalid number of subscribers specified\n");
        return 1;
    }

    fd = open(myfifo, O_WRONLY);
    if (fd == -1) {
        printf("Error: Failed to open named pipe\n");
        return 1;
    }

    
    printf("Enter message to send to subscribers: \n");
    while (fgets(buf, 1024, stdin)) {
        for(int i = 0; i < subs; i++) {
            write(fd, buf, 1024);
        }
        memset(buf, 0, 1024);
        sleep(1);
    }

    close(fd);

    return 0;
}