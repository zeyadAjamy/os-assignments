#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
    char *path = "tmp";
    DIR *dir = opendir(path);
    if(dir == NULL){
        perror("opendir");
        exit(1);
    }
    
    struct dirent *entry;
    struct stat st;
    char *files[100];
    int inodes[100];
    int i = 0;

    while((entry = readdir(dir)) != NULL){
        if(entry->d_type == DT_REG){
            char *file = malloc(strlen(path) + strlen(entry->d_name) + 2);
            sprintf(file, "%s/%s", path, entry->d_name);
            if(stat(file, &st) == -1){
                perror("stat");
                exit(1);
            }

            if (st.st_nlink >= 1) {
                files[i] = file;
                inodes[i] = st.st_ino;
                i++;
            }
        }
    }

    printf ("File ----- Hard links\n");
    // loop over again and prints all the files with the same inode number
    for (int j = 0; j < i; j++) {
        rewinddir(dir);
        int current_inode = inodes[j];
        char *current_file = files[j];
        int count = 0;
        char *files[100];

        while((entry = readdir(dir)) != NULL){
            if(entry->d_type == DT_REG){
                char *file = malloc(strlen(path) + strlen(entry->d_name) + 2);
                sprintf(file, "%s/%s", path, entry->d_name); 
                if(stat(file, &st) == -1){
                    perror("stat");
                    exit(1);
                }
                if (st.st_ino == current_inode) {
                    files[count] = file;
                    count++;
                }
            }
        }

        if (count > 1) {
            printf("%s ----- ", current_file);
            for (int k = 0; k < count; k++) {
                printf("%s ", files[k]);
            }
            printf("\n");
        }
    }
}