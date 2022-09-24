#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;
    pid_t pid1, pid2;
    pid1 = fork();
    start = clock();
    if (pid1 == 0)
    {
        printf("I am the child with [PID - %d, PPID - %d] \n", getpid(), getppid());

        // Calculate the time taken by the child process
        end = clock();
        cpu_time_used = ((double)((end - start)) / CLOCKS_PER_SEC) * 1000;
        printf("Time taken by the child process is %f milliseconds \n", cpu_time_used);
    }
    else
    {
        pid2 = fork();
        start = clock();
        if (pid2 == 0)
        {
            printf("I am the child with [PID - %d, PPID - %d] \n", getpid(), getppid());

            // Calculate the time taken by the child process
            end = clock();
            cpu_time_used = ((double)((end - start)) / CLOCKS_PER_SEC) * 1000;
            printf("Time taken by the child process is %f milliseconds \n", cpu_time_used);
        }
        else
        {
            waitpid(pid2, NULL, 0);
            end = clock();
            printf("Main process id: %d \n", getpid());
            cpu_time_used = ((double)((end - start)) / CLOCKS_PER_SEC) * 1000;
            printf("Time taken by the parent process is %f milliseconds \n", cpu_time_used);
        }
    }
    return 0;
}