#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * amazing_realloc(void * pointer, size_t old_size, size_t new_size){
    // if ptr is NULL, the call is equivalent to malloc(size)
    if(pointer == NULL){ 
        return malloc(new_size);
    }
    // if size is equal to zero, the call is equivalent to free(ptr)
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
    size_t min_size = old_size < new_size ? old_size : new_size;
    memcpy(new_ptr, pointer, min_size * sizeof(pointer));
    
    // Deallocate the memory, so the TAs cannot find memory leaks, vol2:)
    free(pointer);
    return new_ptr;
    
}