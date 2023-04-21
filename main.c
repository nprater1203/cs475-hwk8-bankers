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
  
  //subtract max resources by alloced resources to get available resources
  for(int i = 0; i < NPROC; i++){
    subVector(resources, alloc[i]);
  }

  //test
  printMatrix(need);
  printf("\n");
  int safe = isSafe(resources, alloc, need);
  printf("%d\n", safe);


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