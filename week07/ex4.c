#include <stdio.h>
#include <stdlib.h>

void * amazing_realloc(void * pointer, size_t new_size){
    // If ptr is NULL, the call is equivalent to malloc(size)
    if(pointer == NULL){ 
        return malloc(new_size);
    }
    // If size is equal to zero, the call is equivalent to free(ptr)
    if(new_size == 0){
        free(pointer);
        return NULL;
    }
    
    // Allocate new memory
    void * new_ptr = malloc(new_size);
    if(new_ptr == NULL){
        return NULL; // couldn't allocate memory
    }
    
    // Copy the data from the old memory to the new memory
    for(int i = 0; i < new_size; i++){
        *(char *)(new_ptr + i) = *(char *)(pointer + i);
    }

    // Deallocate the memory, so the TAs cannot find memory leaks, vol2:)
    free(pointer);
    return new_ptr;
}