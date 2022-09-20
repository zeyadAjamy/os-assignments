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

void *add(const void *a, const void *b)
{
    void *result = malloc(sizeof(double));
    *(double *)result = *(double *)a + *(double *)b;
    return result;
}

void *multiply(const void *a, const void *b)
{
    void *result = malloc(sizeof(double));
    *(double *)result = *(double *)a * *(double *)b;
    return result;
}

void *mean(const void *a, const void *b)
{
    void *result = malloc(sizeof(double));
    *(double *)result = (*(double *)a + *(double *)b) / 2;
    return result;
}

int main()
{
    double initial_value = 0;
    double *result = aggregate((void *)&initial_value, sizeof(double), 5,
                               (void *)&initial_value, add);
    printf("add: %f %f %f %f %f = %f", initial_value, initial_value,
           initial_value, initial_value, initial_value, *result);
    free(result);
    printf("\n");
    initial_value = 1;
    result = aggregate((void *)&initial_value, sizeof(double), 5,
                       (void *)&initial_value, multiply);
    printf("multiply: %f %f %f %f %f = %f", initial_value, initial_value,
           initial_value, initial_value, initial_value, *result);
    free(result);
    printf("\n");
}
