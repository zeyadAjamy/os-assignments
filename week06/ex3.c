// Write a program ex3.c to simulate the round robin algorithm,
// which should show the same metrics as the two previous programs.

// Note: for this algorithm, the quantum should be specified by the
// user from stdin.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n = 0, i = 0, j, k, temp;
    int *at, *bt, *ct, *tat, *wt;
    float avg_tat, avg_wt;
    int quantum;

    // Get the numbe of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("At least one process is required \n");
        return 1;
    }

    at = (int *)malloc(n * sizeof(int));
    bt = (int *)malloc(n * sizeof(int));
    ct = (int *)malloc(n * sizeof(int));
    tat = (int *)malloc(n * sizeof(int));
    wt = (int *)malloc(n * sizeof(int));

    // Get the arrival time and burst time of each process
    for (i = 0; i < n; i++)
    {
        // Get the arrival time and burst time of each process
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // sort the processes based on the burst time
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (bt[i] > bt[j])
            {
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
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // calculate average turnaround time and waiting time

    // Get the quantum and on enter, print the metrics
    printf("Enter the quantum: ");
    while (scanf("%d", &quantum) == 1)
        break;

    int rem_bt[n];
    for (i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0;
    while (1)
    {
        int done = 1;
        for (i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = 0;
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    for (i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    avg_tat = 0;
    avg_wt = 0;
    for (i = 0; i < n; i++)
    {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("Average Turnaround Time: %f\n", avg_tat);
    printf("Average Waiting Time: %f\n", avg_wt);

    return 0;
}
