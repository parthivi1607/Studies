#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, x;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;
    if (rank == 0)
    {
        printf("Enter a number: ");
        scanf("%d", &x);
        MPI_Send(&x,1,MPI_INT,1,rank+1,MPI_COMM_WORLD);
        printf("Process 0 has sent number %d to process 1.\n", x);
        MPI_Recv(&x,1,MPI_INT,size-1,0,MPI_COMM_WORLD,&status);
        printf("Process 0 recieved %d.\n", x);
    }
    else
    {
        MPI_Recv(&x,1,MPI_INT,rank-1,rank,MPI_COMM_WORLD,&status);
        x++;
        printf("Process %d recieved %d, sending %d to process %d.\n", rank, x-1, x, (rank+1)%size);
        MPI_Send(&x,1,MPI_INT,(rank+1)%size,(rank+1)%size,MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}