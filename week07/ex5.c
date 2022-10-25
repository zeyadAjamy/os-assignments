#include <stdio.h>
#include <stdlib.h>

int main () {
    char **s;
    char foo[] = "Hello World";
    *s = (char *) foo;
    printf("s is %s\n", *s);
    s[0] = *foo;

    printf("s[0] is %c\n" , s[0]);
    return (0) ;
}