#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }
    int pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    char buf_msg[1024];
    if (pid == 0) {
        while (read(pipefd[0], buf_msg, 1024) > 0) {
            printf("%s", buf_msg);
            memset(buf_msg, 0, 1024); // clear buffer to avoid printing garbage
        }
    } else {
        while (fgets(buf_msg, 1024, stdin) != NULL) {
            write(pipefd[1], buf_msg, strlen(buf_msg));
            memset(buf_msg, 0, 1024);
        }
    }
    return 0;
}