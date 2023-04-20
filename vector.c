#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// TODO - Define vector and matrix operations
//copies every element in vec2 to vec1
cloneVector(int* vec1, int* vec2){
    for(int i = 0; i < NRES; i++){
        vec1[i] = vec2[i];
    }
}

//returns if 1 if every element in vec1 <= to every element in vec2 else returns 0
compareVector(int* vec1, int* vec2){
    for(int i = 0; i < NRES; i++){
        if(vec1[i] > vec2[i]){
            return 0; 
        }
    }
    return 1; 
}

//adds elements of vec2 onto elements of vec1
addVector(int* vec1, int* vec2){
    for(int i = 0; i < NRES; i++){
        vec1[i] += vec2[i];
    }
}