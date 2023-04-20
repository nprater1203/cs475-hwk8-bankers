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

  char *filePath = argv[1];

  //try to open the file and make sure it exists
  FILE * pFile;
  pFile = fopen(filePath,"r");

  if(pFile == NULL){
    printf("Given File Path Not Found\n");
    return 0;
  }


  
  fscanf(pFile, "%d", &NRES);
  fscanf(pFile, "%d", &NPROC);

  int resource[3];

  fscanf(pFile, "%d", &resource[0]);
  fscanf(pFile, "%d", &resource[1]);
  fscanf(pFile, "%d", &resource[2]);


  //read in the demand matrix. as it's a fixed size we can malloc with specific params
  int (*demand)[NPROC] = malloc(sizeof(int[NPROC][NRES]));

  for(int i = 0; i< 15; i++){
    int row = i / 3;
    int col = i % 3;


    fscanf(pFile, "%d", &demand[row][col]);

  }

  //read in alloc mat
  //alloc is the same size as the demand array
  int (*alloc)[NPROC] = malloc(sizeof(int[NPROC][NRES]));
  for(int i = 0; i< 15; i++){
    int row = i / 3;
    int col = i % 3;
    fscanf(pFile, "%d", &alloc[row][col]);

  }





  // TODO: attempt to open scenario file and scan data into allocated structures

  // TODO: Run banker's safety algorithm

  return 0;
}