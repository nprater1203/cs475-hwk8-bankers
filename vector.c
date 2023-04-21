#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// TODO - Define vector and matrix operations
//copies every element in vec2 to vec1
void cloneVector(int* vec1, int* vec2){
    for(int i = 0; i < NRES; i++){
        vec1[i] = vec2[i];
    }
}

//returns if 1 if every element in vec1 <= to every element in vec2 else returns 0
int compareVector(int* vec1, int* vec2){
    for(int i = 0; i < NRES; i++){
        if(vec1[i] > vec2[i]){
            return 0; 
        }
    }
    return 1; 
}

//adds elements of vec2 onto elements of vec1
void addVector(int* vec1, int* vec2){
    for(int i = 0; i < NRES; i++){
        vec1[i] += vec2[i];
    }
}

//subtracts elements of vec1 by elements of vec2
void subVector(int* vec1, int* vec2){
    for(int i = 0; i < NRES; i++){
        vec1[i] -= vec2[i];
    }
}

//subtracts elements of matrix1 by elements matrix2 and puts it in matrix3
void subMatrix(int** matrix1, int** matrix2, int** matrix3){
    for(int i = 0; i < NPROC; i++){
        for(int j = 0; j < NRES; j++){
            matrix3[i][j] = matrix1[i][j] - matrix2[i][j]; 
        }
    }
}

//prints out a given matrix
void printMatrix(int** matrix){
    for(int i = 0; i < NPROC; i++){
        for(int j = 0; j < NRES; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//prints out a given vector
void printVector(int* vec){
    for(int i = 0; i < NRES; i++){
        printf("%d ", vec[i]);
    }
}