/*
	Name: Nicholas P, Mathew Z, Owen RL
	Course: CS 481 OS
	Professor: Dr. Chiu
	Date: 4/28/23
*/

// TODO: function prototypes of vector and matrix operations
extern int NRES; 	// number of resource types
extern int NPROC;	// number of processes


void cloneVector(int* vec1, int* vec2);
int compareVector(int* vec1, int* vec2);
void addVector(int* vec1, int* vec2);
void subVector(int* vec1, int* vec2);
void subMatrix(int** matrix1, int** matrix2, int** matrix3);
void printMatrix(int** matrix);
void printVector(int* vec);
