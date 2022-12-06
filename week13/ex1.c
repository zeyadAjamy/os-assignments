#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 40
#define MAX_LINE_NUMBER 40
#define FILE_NAME "input.txt"
int process_number = 0;
int resources_number = 0;

bool isNumber(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

bool validateInputFormate(char buffer[MAX_LINE_LENGTH][MAX_LINE_NUMBER])
{
    /*
     * 1. the first line should contains 3 numbers representing the number of existing resources
     * 2. the second line should be empty
     * 3. the third line should contains 3 numbers representing the number of available resources
     * 4. the fourth line should be empty
     * 5. each line from the fifth line till the ninth should contains 3 numbers representing the number of resources allocated to each process
     * 6. the tenth line should be empty
     * 7. each line from the eleventh line till the fifteenth should contains 3 numbers representing the number of resources requested by each process
     */

    for (int i = 0; i < resources_number; i++)
    {
        if (!isNumber(buffer[0][i * 2]))
        {
            return false;
        }
    }

    if (buffer[1][0] != '\n')
    {
        return false;
    }

    for (int i = 0; i < resources_number; i++)
    {
        if (!isNumber(buffer[2][i * 2]))
        {
            return false;
        }
    }

    if (buffer[3][0] != '\n')
    {
        return false;
    }

    for (int i = 0; i < process_number; i++)
    {
        for (int j = 0; j < resources_number; j++)
        {
            if (!isNumber(buffer[i + 4][j * 2]))
            {
                return false;
            }
        }
    }

    if (buffer[4 + process_number][0] != '\n')
    {
        return false;
    }

    for (int i = 0; i < process_number; i++)
    {
        for (int j = 0; j < resources_number; j++)
        {
            if (!isNumber(buffer[i + 5 + process_number][j * 2]))
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *fp2 = fopen("output.txt", "w");

    if (fp2 == NULL || fp == NULL)
    {
        printf("Error opening file output.txt \n");
        exit(1);
    }

    // Read line by line
    char buffer[MAX_LINE_LENGTH][MAX_LINE_NUMBER];
    char line[20];
    int i = 0;
    bool stopCounting = false;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (i == 0)
        {
            // increment the number of resources by 1 for each space
            for (int j = 0;; j++)
            {
                if (line[j] == '\n')
                {
                    resources_number++;
                    break;
                }
                if (line[j] == ' ')
                {
                    resources_number++;
                }
            }
        }
        if (i >= 4 && line[0] != '\n' && stopCounting == false)
        {
            process_number++;
        }
        if (i >= 4 && line[0] == '\n')
        {
            stopCounting = true;
        }
        strcpy(buffer[i], line);
        i++;
    }
    fclose(fp);

    // Validate input formate
    if (!validateInputFormate(buffer))
    {
        printf("Invalid input formate \n");
        fprintf(fp2, "Invalid input formate \n");
        exit(1);
    }

    // Get the number of existing resources
    int existingResources[resources_number];
    for (int i = 0; i < resources_number; i++)
    {
        existingResources[i] = atoi(&buffer[0][i * 2]);
    }

    // Get the number of available resources
    int availableResources[resources_number];
    for (int i = 0; i < resources_number; i++)
    {
        availableResources[i] = atoi(&buffer[2][i * 2]);
    }

    // Get the number of resources allocated to each process
    int allocatedResources[process_number][resources_number];
    for (int i = 0; i < process_number; i++)
    {
        for (int j = 0; j < resources_number; j++)
        {
            allocatedResources[i][j] = atoi(&buffer[i + 4][j * 2]);
        }
    }

    // Get the number of resources requested by each process
    int requestedResources[process_number][resources_number];
    for (int i = 0; i < process_number; i++)
    {
        for (int j = 0; j < resources_number; j++)
        {
            requestedResources[i][j] = atoi(&buffer[i + 5 + process_number][j * 2]);
        }
    }

    // If the number of currently assigned resources of a type is greater than the number of existing resources of that type, then the input is invalid
    for (int i = 0; i < resources_number; i++)
    {
        int sum = 0;
        for (int j = 0; j < process_number; j++)
        {
            sum += allocatedResources[j][i];
        }

        int expected = availableResources[i] + sum;
        
        if (expected != existingResources[i])
        {
            printf("Invalid input formate \n");
            fprintf(fp2, "Invalid input formate \n");
            exit(1);
        }
    }

    // Run the program to the end and update the available resources in case of resources releaseing
    int safeSequence[process_number];
    for (int i = 0; i < process_number; i++)
    {
        int satisfied = 0;
        for (int j = 0; j < resources_number; j++)
        {
            if (allocatedResources[i][j] >= requestedResources[i][j])
            {
                satisfied++;
            }
        }
        if (satisfied == resources_number)
        {
            for (int j = 0; j < resources_number; j++)
            {
                availableResources[j] += allocatedResources[i][j];
            }
            safeSequence[i] = i;
        } 
    }
    int deadlockedProcesses[process_number];
    int deadlockedProcessesNumber = 0;
    for (int p = 0; p < process_number; p++)
    {
        for (int r = 0; r < resources_number; r++)
        {
            if (requestedResources[p][r] > availableResources[r])
            {
                deadlockedProcesses[deadlockedProcessesNumber] = p+1;
                deadlockedProcessesNumber++;
                break;
            }
        }
    }

    // Output the result
    if (deadlockedProcessesNumber == 0)
    {
        printf("No deadlock is detected! \n");
        fprintf(fp2, "No deadlock is detected! \n");
    }
    else
    {
        printf("Deadlocked processes: ");
        fprintf(fp2, "Deadlocked processes: ");
        for (int i = 0; i < deadlockedProcessesNumber; i++)
        {
            printf("P%d, ", deadlockedProcesses[i]);
            fprintf(fp2, "P%d, ", deadlockedProcesses[i]);
        }
        printf("\n");
    }

    fclose(fp2);

    return 0;
}