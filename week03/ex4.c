
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *aggregate(void *base, size_t size, int n, void *initial_value,
                void *(*opr)(const void *, const void *))
{
    void *result = malloc(size);
    memcpy(result, initial_value, size);
    for (int i = 0; i < n; i++)
    {
        void *item = malloc(size);
        memcpy(item, base + i * size, size);
        result = opr(result, item);
    }
    return result;
}

void *addInt(const void *a, const void *b){
    int *result = malloc(sizeof(int));
    *result = *(int *)a + *(int *)b;
    return result;
}

void *addDouble(const void *a, const void *b){
    double *result = malloc(sizeof(double));
    *result = *(double *)a + *(double *)b;
    return result;
}

void *multiplyInt(const void *a, const void *b){
    int *result = malloc(sizeof(int));
    *result = *(int *)a * *(int *)b;
    return result;
}

void *multiplyDouble(const void *a, const void *b){
    double *result = malloc(sizeof(double));
    *result = *(double *)a * *(double *)b;
    return result;
}


void *meanInt(const void *a, const void *b){
    int *result = malloc(sizeof(int));
    *result = (*(int *)a + *(int *)b) / 2;
    return result;
}

void *meanDouble(const void *a, const void *b){
    double *result = malloc(sizeof(double));
    *result = (*(double *)a + *(double *)b) / 2;
    return result;
}

int main()
{
    double a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};

    double intial_value = 0;
    double *result = aggregate(a, sizeof(double), 5, &intial_value, addDouble);

    printf("%f\n", *result);

    int intial_value2 = 1;
    int *result2 = aggregate(b, sizeof(int), 5, &intial_value2, multiplyInt);

    printf("%d\n", *result2);

    double intial_value3 = 0;
    double *result3 = aggregate(a, sizeof(double), 5, &intial_value3, meanDouble);

    printf("%f\n", *result3);

    return 0;
}