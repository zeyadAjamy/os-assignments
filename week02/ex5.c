#include <stdio.h>

int tribonacci(int n) {
    if(n == 0) return 0;
    if(n >= 1 && n <= 2) return 1;

    int a = 0, b = 1, c = 1, d = 0;
    for (int i = 0; i < n; i++) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return a;
}

int main() {
    printf("T4: %d\n", tribonacci(4));
    printf("T36: %d\n", tribonacci(36));
    return 0;
}