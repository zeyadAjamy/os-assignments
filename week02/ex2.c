#include <stdio.h>
#include <string.h>

int main()
{
    // declare variables
    char str[256];
    int i = 0;
    char c;

    // ask user to type a string
    printf("Type a string: ");
    while ((c = getchar()) != '.' && c != '\n')
    {
        str[i] = c;
        i++;
    }

    // print string in reverse order
    printf("The string in reverse order is: ");
    printf("\"");
    for (i = strlen(str) - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\"\n"); 
}