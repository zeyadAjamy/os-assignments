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
        printf("xp> ");
        command = malloc(100);
        fgets(command, 100, stdin);
        command[strlen(command) - 1] = '\0';

        if (strcmp(command, "exit") == 0) { // if user types exit, exit
            break;
        }

        args[0] = command;
        args[1] = NULL;

        if (fork() == 0) {
            // run the command in background
            execvp(command, args);
            perror("Error");
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}