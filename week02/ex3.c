#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(char x[256], int s, int t)
{
    // convert the source number to decimal
    if (s < 2 || s > 10 || t < 2 || t > 10)
    {
        printf("cannot convert!\n");
        return 0;
    }
    int decimalNumber = 0;
    int i = 0;
    int len = strlen(x);
    while (i < len)
    {
        decimalNumber = decimalNumber * s + (x[i] - '0');
        i++;
    }

    // convert the decimal to target number
    char target_number_str[100];
    i = 0;
    while (decimalNumber > 0)
    {
        target_number_str[i] = decimalNumber % t + '0';
        decimalNumber /= t;
        i++;
    }
    target_number_str[i] = '\0';

    // reverse the target number
    int j = 0;
    while (j < i / 2)
    {
        char temp = target_number_str[j];
        target_number_str[j] = target_number_str[i - j - 1];
        target_number_str[i - j - 1] = temp;
        j++;
    }
    // print the target number
    printf("%s in base %d is %s in base %d \n", x, s, target_number_str, t);

    return 0;
}

int main()
{
    char number[256];
    int source, target;

    printf("Enter a number: ");
    scanf("%s", number);
    printf("Enter the source base: ");
    scanf("%d", &source);
    printf("Enter the target base: ");
    scanf("%d", &target);

    convert(number, source, target);

    return 0;
}