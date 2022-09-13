#include <limits.h>
#include <stdio.h>

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
    d = __FLT_MAX__;
    e = __DBL_MAX__;

    // print sizes and values
    printf("Size of int: %lu bytes\n", sizeof(a));
    printf("Value of int: %d\n", a);
    printf("Size of unsigned short int: %lu bytes\n", sizeof(b));
    printf("Value of unsigned short int: %hu\n", b);
    printf("Size of signed long int: %lu bytes\n", sizeof(c));
    printf("Value of signed long int: %ld\n", c);
    printf("Size of float: %lu bytes\n", sizeof(d));
    printf("Value of float: %f\n", d);
    printf("Size of double: %lu bytes\n", sizeof(e));
    printf("Value of double: %lf\n", e);

}