#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Wrong input, Usage ./<excutable binary file name> <number of page frames>\n");
        return 0;
    }

    // read file 
    FILE *fp = fopen("input.txt", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int *arr = NULL;
    int size = 0;
    char *token;
    
    if(fp == NULL){
        printf("Error: file not found\n");
        return 0;
    }

    read = getline(&line, &len, fp); // get the first line
    
    // Split the line by space
    token = strtok(line, " ");
    while(token != NULL){
        arr = realloc(arr, sizeof(int) * (size + 1));
        arr[size] = atoi(token);
        size++;
        token = strtok(NULL, " ");
    }

    // Close file
    fclose(fp);

    // Validate input argv[1] should be a number
    for (int i = 0; i < strlen(argv[1]); i++){
        if(argv[1][i] < '0' || argv[1][i] > '9'){
            printf("Wrong input, Usage ./<excutable binary file name> <number of page frames>\n");
            return 0;
        }
    }

    int frames_number = atoi(argv[1]);
    int *page_table = malloc(sizeof(int) * frames_number);
    int *age_table = malloc(sizeof(int) * frames_number);
    int *ref_table = malloc(sizeof(int) * frames_number);

    // Initialize page table, age table, ref table
    for(int i = 0; i < frames_number; i++){
        page_table[i] = -1;
        age_table[i] = 0;
        ref_table[i] = 0;
    }

    int hit = 0;
    int miss = 0;

    for(int i = 0; i < size; i++){

        /*
         * 1. Check if the page is in the page table
         * 2. If it is in the page table, increase hit
         * 3. If it is not in the page table, increase miss 
        */

        int found = 0;
        for(int j = 0; j < frames_number; j++){
            if(page_table[j] == arr[i]){
                found = 1;
                hit++;
                ref_table[j] = 1;
                break;
            }
        }

        if(found == 0){
            miss++;
            int found_empty = 0;
            for(int j = 0; j < frames_number; j++){
                if(page_table[j] == -1){
                    page_table[j] = arr[i];
                    age_table[j] = 0;
                    ref_table[j] = 1;
                    found_empty = 1;
                    break;
                }
            }

            if(found_empty == 0){
                int min = 0;
                for(int j = 0; j < frames_number; j++){
                    if(age_table[j] < age_table[min]){
                        min = j;
                    }
                }

                page_table[min] = arr[i];
                age_table[min] = 0;
                ref_table[min] = 1;
            }
        }
        
        /** According to Tanenbaum, A. S. (2013). Modern operating systems (4th ed.). Upper Saddle River, NJ: Pearson Education.
         *  Page 213, we need to shift the age table to the right by 1 bit before adding the new reference bit to the left most bit (MSB).
        */

        for(int j = 0; j < frames_number; j++){
            age_table[j] = age_table[j] >> 1;
            age_table[j] = age_table[j] | (ref_table[j] << 7);
            ref_table[j] = 0;
        }
    }

    printf("Hit/Miss ratio: %f\n", (float)hit/miss);
    
    free(arr);
    free(line);
    free(token);
    free(page_table);
    free(age_table);
    free(ref_table);
}