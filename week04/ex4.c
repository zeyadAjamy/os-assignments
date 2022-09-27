#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char *command;
    char *args[3];

    while (1) {
        printf("xp> ");
        command = malloc(100);
        fgets(command, 100, stdin);

        command[strlen(command) - 1] = '\0';

        if (strcmp(command, "exit") == 0) { // if user types exit, exit
            break;
        }

        // split the command into the command and the argument
        args[0] = strtok(command, " ");
        args[1] = strtok(NULL, " ");
        args[2] = NULL;
        int s = 0;
        if (fork() == 0) {
            execvp(args[0], args);
            printf("Unknown command\n");
            exit(1);
        } else {
            wait(NULL);
        }

        free(command);
    }

    return 0;
} 