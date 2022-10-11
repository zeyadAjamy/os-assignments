#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct process {
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} process;

void sort(process *p, int n) {
    int i, j;
    process temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}


int main() {
    int n, time = 0, total_waiting_time = 0, total_turnaround_time = 0;
    float average_waiting_time, average_turnaround_time;
    process p[MAX];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }
    sort(p, n);

    // Round Robin Scheduling considring the arrival time of the processes
    int quantum;
    printf("Enter the quantum: ");
    scanf("%d", &quantum);

    int remaining = n;
    int done[n];
    for (int i = 0; i < n; i++) {
        done[i] = 0;
    }
    // create a queue
    int queue[n];
    int front = 0, rear = 0;
    int index = 0;
     // find min arrival time
    int min = 0;
    for (int j = 0; j < n; j++) {
        if (p[j].arrival_time < p[min].arrival_time) {
            min = j;
        }
    }
    time = p[min].arrival_time;
    // Handle quantum time equal to 1
    if (quantum == 1) {
        while (remaining > 0) {
            for (int i = 0; i < n; i++) {
                if (p[i].arrival_time <= time && done[i] == 0) {
                    queue[rear] = i;
                    rear++;
                }
            }
            if (front == rear) {
                time++;
                continue;
            }
            index = queue[front];
            front++;
            p[index].remaining_time--;
            time++;
            if (p[index].remaining_time == 0) {
                p[index].turnaround_time = time - p[index].arrival_time;
                p[index].waiting_time = p[index].turnaround_time - p[index].burst_time;
                total_waiting_time += p[index].waiting_time;
                total_turnaround_time += p[index].turnaround_time;
                done[index] = 1;
                remaining--;
            }
        }
    } else {
        while (remaining > 0) {
            for (int i = 0; i < n; i++) {
                if (p[i].arrival_time <= time && done[i] == 0) {
                    queue[rear] = i;
                    rear++;
                }
            }
            if (front == rear) {
                time++;
                continue;
            }
            index = queue[front];
            front++;
            if (p[index].remaining_time > quantum) {
                p[index].remaining_time -= quantum;
                time += quantum;
            } else {
                time += p[index].remaining_time;
                p[index].remaining_time = 0;
            }
            if (p[index].remaining_time == 0) {
                p[index].turnaround_time = time - p[index].arrival_time;
                p[index].waiting_time = p[index].turnaround_time - p[index].burst_time;
                total_waiting_time += p[index].waiting_time;
                total_turnaround_time += p[index].turnaround_time;
                done[index] = 1;
                remaining--;
            } else {
                queue[rear] = index;
                rear++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    average_waiting_time = (float) total_waiting_time / n;
    average_turnaround_time = (float) total_turnaround_time / n;

    printf("Process\tAT\tBT\tCT\tTT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d \n", i + 1, p[i].arrival_time, p[i].burst_time, p[i].turnaround_time + p[i].arrival_time, p[i].turnaround_time, p[i].waiting_time);
    }

    printf("Average waiting time: %f\n", average_waiting_time);
    printf("Average turnaround time: %f\n", average_turnaround_time);
    return 0;
}
