#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank;
	char str[5] = "HeLlO";
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(str[rank]>='A' && str[rank]<='Z')
		str[rank] += 32;
	else if(str[rank]>='a' && str[rank]<='z')
		str[rank] -=32;
	MPI_Finalize();
	printf("Modified string by process %d: %s\n", rank, str);
	return 0;
}