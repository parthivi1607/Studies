#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, m, arr[100], brr[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    float crr[100], avg;
    if(rank==0)
    {
        printf("Enter value for m: ");
        scanf("%d",&m);
        printf("Enter %d values:\n", size*m);
        for(int i=0;i<size*m;i++)
            scanf("%d",&arr[i]);
    }
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(arr, m, MPI_INT, brr, m, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received: ", rank);
    avg = 0;
    for(int i=0;i<m;i++)
    {
        printf("%d ", brr[i]);
        avg += brr[i];
    }
    printf("\n");
    avg = avg/m;
    printf("Process %d sending %f.\n", rank, avg);
    MPI_Gather(&avg, 1, MPI_FLOAT, crr, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
    if(rank==0)
    {
        avg=0;
        for(int i=0;i<size;i++)
            avg += crr[i];
        avg = avg/size;
        printf("Total avg = %f\n", avg);
    }
    MPI_Finalize();
    return 0;
}
