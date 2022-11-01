#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    size_t memSize = 10 * 1024 * 1024;
    
    void *block = malloc(memSize);
    memset(block, 0, memSize);
    sleep(1);
    
    for (int i = 0; i < 9; i++) {
        block = malloc(memSize);
        memset(block, 0, memSize);
        sleep(1);
    }
    
    free(block);
    return 0;
}

// Using Vmstat:
//----------------
// For 10 MB it s0, s1 are both zeros, but 
// for 1 GB so start to increase after that s1 starts to increase
// Then the proccess has been killed by OOM killer.

// using top:
//--------------
// For 10 MB no change in memory usage, however for 1 GM
// the memory usage is increasing and then the process is killed by OOM killer.