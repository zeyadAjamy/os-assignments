#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long convert(long long x, int s, int t)
{
    // convert long long to string 
    char str[100];
    sprintf(str, "%lld", x);

    // check is the source and target base are valid, [2,10] 
    if (s < 2 || s > 10 || t < 2 || t > 10)
    {
        return -1;
    }

    // check if the number is not in the range of the source base
    for (int k = 0; k < strlen(str); k++)
    {
        if (str[k] - '0' >= s)
        {
            return -1;
        }
    }


    // convert the source number to decimal
    int decimalNumber = 0;
    int i = 0;
    int len = strlen(str);
    while (i < len)
    {
        decimalNumber = decimalNumber * s + (str[i] - '0');
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
    // convert char to long long number and return
    return atoll(target_number_str);
}

int main()
{
    long long int number;
    int source, target;

    printf("Enter a number: ");
    scanf("%lli", &number);
    printf("Enter the source base: ");
    scanf("%d", &source);
    printf("Enter the target base: ");
    scanf("%d", &target);

    long long int res = convert(number, source, target);
    if(res == -1){
        printf("\ncannot convert!\n");
    } else {
        printf("%lld\n", res);
    }

    return 0;
}