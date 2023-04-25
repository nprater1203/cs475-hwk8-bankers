/*
    Name: Nicholas P, Mathew Z, Owen RL
	Course: CS 481 OS
	Professor: Dr. Chiu
	Date: 4/28/23
*/

/* declarations related to banker's algorithm */
extern int NRES; 	// number of resource types
extern int NPROC;	// number of processes

int isSafe(int* available, int** alloc, int** need);