#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int * temp_arr = (int *)malloc(n * sizeof(int));

    // Check if the memory has been successfully allocated by malloc or not
    if (temp_arr == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    // Assign values to the elements of the array
    for (int i = 0; i < n; ++i)
    {
        *(temp_arr + i) = i;
    }

    // Print the elements of the array stored in the memory in one line
    printf("The elements are: \n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", *(temp_arr + i));
    }

    printf("\n");
    // Deallocate the memory, so the TAs cannot find memory leaks :)
    free(temp_arr);

    return 0;
}