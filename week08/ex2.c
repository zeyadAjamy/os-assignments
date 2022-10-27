#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    size_t memSize = 10 * 1024 * 1024;
    for (int i = 0; i < 10; i++) {
        void *ptr = malloc(memSize);
        memset(ptr, 0, memSize);
        sleep(1);
    }
    return 0;
}

// Using Vmstat:
//----------------
// For 10 MB it s0, s1 are both zeros, but 
// for 1 GB so start to increase after that s1 starts to increase
// Then the proccess has been killed by OOM killer.

// using top:
//-----------
// the memory usage is increasing and then the process is killed by OOM killer.