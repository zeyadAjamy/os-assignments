#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, i = 0, j, k, temp;
    int *at, *bt, *ct, *tat, *wt;
    float avg_tat, avg_wt;

    printf("Enter the number of processes: ");
    while(scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer: ");
    }

    at = (int *)malloc(n * sizeof(int));
    bt = (int *)malloc(n * sizeof(int));
    ct = (int *)malloc(n * sizeof(int));
    tat = (int *)malloc(n * sizeof(int));
    wt = (int *)malloc(n * sizeof(int));
    
    // Get the arrival time and burst time of each process
    for(i = 0; i < n; i++) {
        printf("Enter the arrival time of process %d: ", i + 1);
        while(scanf("%d", &at[i]) != 1 || at[i] < 0)
        {
            printf("Invalid input. Please enter a non-negative integer: ");
        }
        printf("Enter the burst time of process %d: ", i + 1);
        while(scanf("%d", &bt[i]) != 1 || bt[i] <= 0)
        {
            printf("Invalid input. Please enter a positive integer: ");
        }
    }

    // sort the processes based on arrival time
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (at[i] > at[j]) {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
    
    // calculate completion time
    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++)
        ct[i] = ct[i - 1] + bt[i];

    // calculate turnaround time and waiting time
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // calculate average turnaround time and waiting time
    avg_tat = 0;
    avg_wt = 0;
    for (i = 0; i < n; i++) {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    avg_tat /= n;
    avg_wt /= n;

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    printf("Average Turnaround time: %f\n", avg_tat);
    printf("Average Waiting time: %f\n", avg_wt);
    
    // free memory
    free(at);
    free(bt);
    free(ct);
    free(tat);
    free(wt);

    return 0;
}