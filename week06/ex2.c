#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n = 0, i = 0, j, k, temp;
    int *at, *bt, *ct, *tat, *wt;
    float avg_tat, avg_wt;

    if(argc < 2) {
        printf("At least two arguments are required \n");
        return 1;
    } else if (atoi(argv[1]) < 1) {
        printf("At least one process is required \n");
        return 1;
    } else if (argc - 1 < atoi(argv[1])*2) {
        printf("At least %d arguments are required \n", atoi(argv[1])*2 + 1 );
        return 1;
    }

    n = atoi(argv[1]);

    at = (int *)malloc(n * sizeof(int));
    bt = (int *)malloc(n * sizeof(int));
    ct = (int *)malloc(n * sizeof(int));
    tat = (int *)malloc(n * sizeof(int));
    wt = (int *)malloc(n * sizeof(int));

    // Get the arrival time and burst time of each process
    for(i = 0; i < n; i++) {
        at[i] = atoi(argv[i + 1]);
        bt[i] = atoi(argv[i + 2]);
    }

    // sort the processes based on the burst time
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (bt[i] > bt[j]) {
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

    // print the results
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    
    printf("Average TAT: %f \n", avg_tat);
    printf("Average WT: %f \n", avg_wt);

    return 0;
}
