#include <limits.h>
#include <stdio.h>
#include <float.h>

int main(){
    // declare variables
    int a;
    unsigned short int b;
    signed long int c;
    float d;
    double e;

    // Assign maximum values to variables
    a = INT_MAX;
    b = SHRT_MAX;
    c = LONG_MAX;
    d = FLT_MAX;
    e = DBL_MAX;

    // print sizes and values
    printf("Size of int: %lu bytes\n", sizeof(a));
    printf("Value of int: %d\n", a);
    printf("\n");
    printf("Size of unsigned short int: %lu bytes\n", sizeof(b));
    printf("Value of unsigned short int: %hu\n", b);
    printf("\n");
    printf("Size of signed long int: %lu bytes\n", sizeof(c));
    printf("Value of signed long int: %ld\n", c);
    printf("\n");
    printf("Size of float: %lu bytes\n", sizeof(d));
    printf("Value of float: %f\n", d);
    printf("\n");
    printf("Size of double: %lu bytes\n", sizeof(e));
    printf("Value of double: %lf\n", e);
}