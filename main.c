/*
    Name: Nicholas P, Mathew Z, Owen RL
	  Course: CS 481 OS
	  Professor: Dr. Chiu
	  Date: 4/28/23
*/

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"

int NRES; 	// number of resource types
int NPROC;	// number of processes

int main(int argc, char *argv[])
{

  // check we have a file path
  if (argc  <2)
  {
    printf("No Input File Path Given\n");
    return 0;
  }

  //try to open the file and make sure it exists
  FILE *pFile;
  pFile = fopen(argv[1],"r");

  if(pFile == NULL){
    printf("Given File Path Not Found\n");
    return 0;
  }
  
  fscanf(pFile, "%d", &NRES);
  fscanf(pFile, "%d", &NPROC);

  int* resources = (int*)malloc(NRES * sizeof(int));

  for(int i = 0; i < NRES; i++){
    fscanf(pFile, "%d", &resources[i]);
  }

  //read in the demand matrix. as it's a fixed size we can malloc with specific params
  int** demand = malloc(NPROC * sizeof(int*));
  for(int i = 0; i < NPROC; i++){
    demand[i] = (int*)malloc(NRES * sizeof(int));
  }

  for(int i = 0; i < NPROC; i++){
    for(int j = 0; j < NRES; j++){
      fscanf(pFile, "%d", &demand[i][j]);
    }
  }

  //read in alloc mat
  //alloc is the same size as the demand array
  int** alloc = malloc(NPROC * sizeof(int*));
  for(int i = 0; i < NPROC; i++){
    alloc[i] = (int*)malloc(NRES * sizeof(int));
  }

  for(int i = 0; i < NPROC; i++){
    for(int j = 0; j < NRES; j++){
      fscanf(pFile, "%d", &alloc[i][j]);
    }
  }

  fclose(pFile);

  //initialize and create need matrix 
  int** need = malloc(NPROC * sizeof(int*));
  for(int i = 0; i < NPROC; i++){
    need[i] = (int*)malloc(NRES * sizeof(int));
  }
  subMatrix(demand, alloc, need);

  //Sanity check
  // Add up all the columns in alloc matric and make sure that it doesn't have more than the corresponding resource column
  int sanityCheck = 1; 
  for(int i = 0; i < NRES; i++)
  {
    int columnSum = 0;
    for(int j = 0; j < NPROC; j++)
    {
      columnSum += alloc[i][j];
    }

    if(columnSum > resources[i])
    {
      printf("Integrity test failed: allocated resources exceed total resources\n");
      sanityCheck = 0;
      break;
    }
  } 

  // No element in alloc 2D array is greater than any element in demand 2D array
  for(int i = 0; i < NPROC; i++)
  {
    for(int j = 0; j < NRES; j++)
    {
      if(alloc[i][j] > demand[i][j])
      {
        printf("Integrity test failed: allocated resources exceed demand for Thread %d\n",i);
        printf("Need %d instances of resource %d\n", demand[i][j] - alloc[i][j], j);
        sanityCheck = 0; 
        break;
      }
    }
  }


  //call isSafe if sanity checks are passed
  if(sanityCheck){
    //subtract max resources by alloced resources to get available resources
    for(int i = 0; i < NPROC; i++){
      subVector(resources, alloc[i]);
    }
    isSafe(resources, alloc, need);
  }
  

  //free vectors and matrices
  free(resources);
  for(int i = 0; i < NPROC; i++){
    free(demand[i]);
  }
  free(demand);
  for(int i = 0; i < NPROC; i++){
    free(alloc[i]);
  }
  free(alloc);
  for(int i = 0; i < NPROC; i++){
    free(need[i]);
  }
  free(need);




  // TODO: attempt to open scenario file and scan data into allocated structures

  // TODO: Run banker's safety algorithm

  return 0;
}