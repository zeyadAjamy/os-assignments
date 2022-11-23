#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dir = opendir("/");
    struct dirent *entery;

    if (dir != NULL) {
        while ((entery = readdir (dir)) != NULL) {
            printf ("%s ", entery->d_name);
        }
        closedir (dir);
    } else {
        perror ("Directory not found");
        return EXIT_FAILURE;
    }
    return 0;
}