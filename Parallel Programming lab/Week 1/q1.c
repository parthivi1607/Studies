#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"
#include <math.h>

int main(int argc, char *argv[])
{
	int rank, x = 2;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int ans = pow(x,rank);
	printf("%d ^ %d = %d\n", x, rank, ans);
	MPI_Finalize();
	return 0;
}