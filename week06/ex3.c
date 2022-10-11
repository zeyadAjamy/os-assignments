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

    // sort the processes based on the arriving time
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // Get the quantum and on enter, print the metrics
    printf("Enter the quantum: ");
    while (scanf("%d", &quantum) == 1)
        break;

    // Round robin algorithm
    int time = 1;
    int *ready_queue = (int *)malloc(n * sizeof(int));
    int *bt_copy = (int *)malloc(n * sizeof(int));
    int remaining = n;
    // Round robin algorithm consdiering the arrival time of the processes
    for(i = 0; i < n; i++)
    {
        bt_copy[i] = bt[i];
    }
    int min_bt = 9999, min_bt_index = 0;
    while (remaining > 0)
    {
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && bt_copy[i] < min_bt && bt_copy[i] > 0)
            {
                min_bt = bt_copy[i];
                min_bt_index = i;
            }
        }
        if (min_bt == 9999)
        {
            time++;
            continue;
        }
        if (bt_copy[min_bt_index] <= quantum)
        {
            time += bt_copy[min_bt_index];
            bt_copy[min_bt_index] = 0;
            remaining--;
            ct[min_bt_index] = time;
        }
        else
        {
            bt_copy[min_bt_index] -= quantum;
            time += quantum;
        }
        min_bt = 9999;
    }

    // Calculate the turn around time and waiting time
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // calculate the average turnaround time and waiting time
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
