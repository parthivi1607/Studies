#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, arr[100], val, p;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank==0)
    {
        printf("Enter %d values:\n",size);
        for(int i=0;i<size;i++)
            scanf("%d",&arr[i]);
    }
    MPI_Scatter(arr, 1, MPI_INT, &val, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received %d.\n", rank, val);
    p=1;
    for(int i=2;i<=val;i++)
        p *= i;
    printf("Process %d sending %d.\n", rank, p);
    MPI_Gather(&p, 1, MPI_INT, arr, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if(rank==0)
    {
        p=0;
        for(int i=0;i<size;i++)
            p += arr[i];
        printf("Sum of factorials = %d\n", p);
    }
    MPI_Finalize();
    return 0;
}
