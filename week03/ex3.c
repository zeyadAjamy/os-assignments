#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 256
#define MAX_SUBDIRS 8
#define MAX_FILENAME 63
#define MAX_PATH 2048
#define MAX_FILEDATA 1024

struct File {
    int id;
    char name[MAX_FILENAME];
    int size;
    char data[MAX_FILEDATA];
    struct Directory *parent;
};

struct Directory {
    struct File *files[MAX_FILES];
    struct Directory *directories[MAX_SUBDIRS];
    int nf;
    int nd;
    char path[MAX_PATH];
};

void add_to_file(struct File *file, const char *str) {
    strcpy(file->data, str);
    file->size = strlen(str) + 1;
}

void append_to_file(struct File *file, const char *str) {
    strcat(file->data, str);
    file->size += strlen(str);
}

void pwd_file(struct File *file) {
    printf("%s/%s", file->parent->path, file->name);
}

void add_file(struct File *file, struct Directory *dir) {
    dir->files[dir->nf++] = file;
    file->parent = dir;
}

int main() {
    struct Directory *root = malloc(sizeof(struct Directory));
    strcpy(root->path, "/");
    root->nf = 0;
    root->nd = 0;

    struct Directory *home = malloc(sizeof(struct Directory));
    strcpy(home->path, "/home");
    home->nf = 0;
    home->nd = 0;
    root->directories[root->nd++] = home;

    struct Directory *bin = malloc(sizeof(struct Directory));
    strcpy(bin->path, "/bin");
    bin->nf = 0;
    bin->nd = 0;
    root->directories[root->nd++] = bin;

    struct File *bash = malloc(sizeof(struct File));
    strcpy(bash->name, "bash");
    add_to_file(bash, "Bourne Again Shell!!");
    add_file(bash, bin);

    struct File *ex31 = malloc(sizeof(struct File));
    strcpy(ex31->name, "ex3 1.c");
    add_to_file(ex31, "int printf(const char * format, ...);");
    add_file(ex31, home);

    struct File *ex32 = malloc(sizeof(struct File));
    strcpy(ex32->name, "ex3 2.c");
    add_to_file(ex32, "//This is a comment in C language");
    add_file(ex32, home);

    append_to_file(ex31, "int main(){printf(\"Hello World!\")}");

    for (int i = 0; i < bin->nf; i++) {
        pwd_file(bin->files[i]);
        printf("\n");
    }
    for (int i = 0; i < home->nf; i++) {
        pwd_file(home->files[i]);
        printf("\n");
    }

    return 0;
}