#include <stdio.h>
#include <stdlib.h>

int foo(int age) {
    return 2022 - age;    
}

int main() {
    const int x = 10;
    int *q = &x;
    
    const int * const p = (int *) malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        *((int *) p + i) = x;
    }
    printf("Addresses:\n");
    for (int i = 0; i < 5; i++) {
        printf("%p\n", (int *) p + i);
    }
    printf("Ages: \n");
    for (int i = 0; i < 5; i++) {
        int age;
        scanf("%d", &age);
        *((int *) p + i) = age;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", foo(*((int *) p + i)));
    }
    printf("\n");
    free((int *) p);
    return 0;
}