#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(){
    char * myfifo = "/tmp/ex1";
    char buf[1024];
    
    int file = open(myfifo, O_RDONLY);
    if (file == -1) {
        printf("Error: Failed to open named pipe\n");
        return 1;
    }

    while (read(file, buf, 1024) > 0) {
        printf("Message: %s", buf); // print the publisher msg
        memset(buf, 0, 1024); // clear the buffer
        sleep(1);
    }

    close(file);
    return 0;
}