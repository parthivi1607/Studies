#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank, size, a=15, b=10;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(size != 4)
	{
		printf("Error! Enter only 4 processes.\n");
		MPI_Abort(MPI_COMM_WORLD, 1);
	}
	else
	{
		if(rank==0) printf("%d + %d = %d\n", a, b, (a+b));
		else if(rank==1) printf("%d - %d = %d\n", a, b, (a-b));
		else if(rank==2) printf("%d * %d = %d\n", a, b, (a*b));
		else if(rank==3) printf("%d / %d = %f\n", a, b, (a*1.0/b));
	}
	MPI_Finalize();
	return 0;
}