#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"


// TODO - Safety Algorithm goes here
int isSafe(int* available, int** alloc, int** need){
    int* work = (int*)malloc(NRES * sizeof(int)); 
    cloneVector(available, work);
    int* finish = (int*)malloc(NPROC * sizeof(int)); 
    for(int i = 0; i < NPROC; i++){
        finish[i] = 0;
    }
    
    int thread = 0; 
    while(finish[thread] == 0 && compareVector(need[thread], work)){
        
    }
}