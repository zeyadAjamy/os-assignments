#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    size_t memSize = 10 * 1024 * 1024;
    for (int i = 0; i < 10; i++) {
        void *ptr = malloc(memSize);
        memset(ptr, 0, memSize);
        sleep(1);
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory usage:\n");
        printf("Max resident set size: %ld\n", usage.ru_maxrss);
        printf("Integral shared memory size: %ld\n", usage.ru_ixrss);
        printf("Integral unshared data size: %ld\n", usage.ru_idrss);
        printf("Integral unshared stack size: %ld\n", usage.ru_isrss);
    }
    return 0;
}