#include <stdio.h>

void trianglePattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void upsideDownPattern(int n) {
    trianglePattern(n+1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("*");
        }
        printf("\n");
    }

}

void regularPattern(int n){
    char c = '*';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", c);
        }
        printf("\n");
    }
}
int main() {
    trianglePattern(7);
    printf("\n");
    upsideDownPattern(3);
    printf("\n");
    regularPattern(7);

    
    return 0;
}
