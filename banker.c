#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"


int isSafeHelper(int** alloc, int** need, int* work, int* finish, int* safeSeq, int pos) {
    if (pos == NPROC) { // All processes have been added to the safe sequence
        //print sequence
        printf("SAFE: ");
        for (int i = 0; i < NPROC; i++) {
            printf("T%d ", safeSeq[i]);
        }
        printf("\n");
        return 1;
    }

    int safe = 0;
    for (int i = 0; i < NPROC; i++) {
        if (!finish[i] && compareVector(need[i], work)) {   // If process i is not finished and can be executed safely
            // Mark it as finished, add its resources to work and update the safe sequence
            finish[i] = 1;
            addVector(work, alloc[i]);
            safeSeq[pos] = i;
            // Recursively call the function with updated state
            safe = isSafeHelper(alloc, need, work, finish, safeSeq, pos+1);
            // Undo the changes for backtracking
            finish[i] = 0;
            subVector(work, alloc[i]);
        }
    }
    return safe;
}

int isSafe(int* available, int** alloc, int** need) {
    int* work = (int*) malloc(NRES * sizeof(int));
    cloneVector(work, available);

    int* finish = (int*) malloc(NPROC * sizeof(int));
    for (int i = 0; i < NPROC; i++) {
        finish[i] = 0;
    }

    int* safeSeq = (int*) malloc(NPROC * sizeof(int));
    for (int i = 0; i < NPROC; i++) {
        safeSeq[i] = -1;
    }
    int safe = isSafeHelper(alloc, need, work, finish, safeSeq, 0);

    if(!safe){
        //prints threads that aren't in the safe sequence
        printf("UNSAFE: ");
        for(int i = 0; i < NPROC; i++){
            int found = 0;
            for (int j = 0; j < NPROC; j++) {
                if(safeSeq[j] == i){
                    found = 1; 
                }
            }
            if(!found){
                printf("T%d ", i);
            }
        }
        printf("can't finish\n");
    }

    free(work);
    free(finish);
    free(safeSeq);
    return safe; 
}
