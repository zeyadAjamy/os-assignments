#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

struct Thread {
    pthread_t id;
    int i;
    char message[256];
};


void *thread(void *arg) {
    struct Thread *t = (struct Thread *)arg;
    printf("Thread %ld prints message: %s\n", t->id, t->message);
    printf("Thread %d exits\n", t->i);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int n = 0;
    n = atoi(argv[1]);
    struct Thread t[n];
    for (int i = 0; i < n; i++) {
        t[i].i = i;
        sprintf(t[i].message, "Hello from thread %d", i);
        pthread_create(&t[i].id, NULL, thread, &t[i]);
        printf("Thread %d is created\n", i);
        pthread_join(t[i].id, NULL);
    }
    return 0;
}
