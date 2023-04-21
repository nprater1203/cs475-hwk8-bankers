#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"


// TODO - Safety Algorithm goes here
int isSafe(int* available, int** alloc, int** need){
    int* work = (int*)malloc(NRES * sizeof(int)); 
    cloneVector(work, available);
    int* finish = (int*)malloc(NPROC * sizeof(int)); 
    for(int i = 0; i < NPROC; i++){
        finish[i] = 0;
    }
    
    printf("SEQ: ");
    int done = 0;
    while(!done) {
        done = 1;
        for(int i=0; i<NPROC; i++) {
            if(!finish[i] && compareVector(need[i], work)) {
                printf("T%d ", i);
                addVector(work, alloc[i]);
                finish[i] = 1;
                done = 0;
            }
        }
    }
    printf("\n");

    int safe = 1;
    for(int i=0; i<NPROC; i++) {
        if(!finish[i]) {
            safe = 0;
            break;
        }
    }    

    free(work);
    free(finish);
    return safe; 
}