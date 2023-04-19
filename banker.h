/* declarations related to banker's algorithm */
extern int NRES; 	// number of resource types
extern int NPROC;	// number of processes

int isSafe(int* available, int** alloc, int** need);