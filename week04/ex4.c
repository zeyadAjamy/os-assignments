#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char *command;
    char *args[2];

    while (1) {
        printf("xp: $ ");
        command = malloc(100);
        fgets(command, 100, stdin);
        command[strlen(command) - 1] = '\0';

        if (strcmp(command, "exit") == 0) { // if user types exit, exit
            break;
        }

        args[0] = command;
        args[1] = NULL;

        // execute the command in a child process
        pid_t pid = fork();
        if (pid == 0) {
            execvp(command, args);
            printf("Command not found\n");
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}