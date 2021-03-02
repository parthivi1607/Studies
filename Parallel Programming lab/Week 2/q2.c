#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int rank, size, x=100;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	if(rank==0)
	{
		for(int i=1;i<size;i++)
		{
			MPI_Send(&x,1,MPI_INT,i,i,MPI_COMM_WORLD);
			printf("Process 0 has sent number to process %d.\n",i);
		}
	}
	else
	{
		MPI_Recv(&x,1,MPI_INT,0,rank,MPI_COMM_WORLD,&status);
		printf("Process %d has received number - %d.\n",rank,x);
	}
	MPI_Finalize();
	return 0;
}