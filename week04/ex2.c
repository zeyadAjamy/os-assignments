#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int u[120], v[120];
    for (int i = 0; i < 120; i++)
    {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }
    int pid;
    for (int i = 0; i < n; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            int sum = 0;
            for (int j = i * 120 / n; j < (i + 1) * 120 / n; j++)
            {
                sum += u[j] * v[j];
            }
            FILE *fp = fopen("temp.txt", "a");
            fprintf(fp, "%d ", sum);
            fclose(fp);
            exit(0); // exit the child process
        }
    }
    // wait for all child processes to complete
    for (int i = 0; i < n; i++) wait(NULL);

    FILE *fp = fopen("temp.txt", "r");
    int sum = 0;
    int temp;
    while (fscanf(fp, "%d", &temp) != EOF)
    {
        sum += temp;
    }
    printf("The dot product of the vectors is: %d \n", sum);
    return 0;
}