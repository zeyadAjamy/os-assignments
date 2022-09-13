#include <stdio.h>
#include <ctype.h>

int count(char s[256], char c) {
    int i = 0;
    int count = 0;
    c = tolower(c);
    while (s[i] != '\0') {
        if (tolower(s[i]) == c) {
            count++;
        }
        i++;
    }
    return count;
}

void countAll(char s[256]) {
    int i = 0;
    while (s[i] != '\0') {
        printf("%c:%d", tolower(s[i]), count(s, s[i]));
        if(s[i+1] != '\0') {
            printf(", ");
        }
        i++;
    }
    printf("\n");
}

int main(void) {
    char s[256];
    printf("Enter a string: ");
    scanf("%[^\n]s", s);
    countAll(s);
    return 0;
}