#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, x;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;
    
    if(rank==0)
    {
        int arr[size - 1];
        printf("Enter %d numbers:\n", size - 1);
        for (int i = 0; i < size - 1; i++)
            scanf("%d", &arr[i]);

        int buf[100];
        int size_b = sizeof(buf);
        MPI_Buffer_attach(buf, size_b);
        for (int i=1; i<size; i++)
        {
            MPI_Bsend(&arr[i-1],1,MPI_INT,i,i,MPI_COMM_WORLD);
            printf("Process 0 has sent number %d to process %d.\n", arr[i-1], i);
        }
        MPI_Buffer_detach(buf, &size_b);
    }
    else if(rank%2==0)
    {
        MPI_Recv(&x,1,MPI_INT,0,rank,MPI_COMM_WORLD,&status);
        printf("Process %d - square of recvd no. = %d.\n", rank, x*x);
    }
    else
    {
        MPI_Recv(&x, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
        printf("Process %d - cube of recvd no. = %d.\n", rank, x*x*x);
    }
    MPI_Finalize();
    return 0;
}