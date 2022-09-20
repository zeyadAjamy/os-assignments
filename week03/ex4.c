#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *))
{
    void *result = malloc(size);
    memcpy(result, initial_value, size);
    for (int i = 0; i < n; i++)
    {
        void *temp = opr(result, base + i * size);
        memcpy(result, temp, size);
        free(temp);
    }
    return result;
}


int main()
{
    double initial_value = 0;
    double arr[] = {1, 2, 3, 4, 5};
    double *result = aggregate((void *)arr, sizeof(double), 5,
                               (void *)&initial_value, mean);
    printf("mean: %f %f %f %f %f = %f", arr[0], arr[1], arr[2], arr[3], arr[4], *result);
    free(result);
    printf("\n");

    int arr2[] = {1, 2, 3, 4, 5};
    int *result2 = aggregate((void *)arr2, sizeof(int), 5,
                             (void *)&initial_value, multiply);
    printf("Multiply: %d %d %d %d %d = %d", arr2[0], arr2[1], arr2[2], arr2[3], arr2[4], *result2);
    free(result2);
    printf("\n");

    return 0;
}
