#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, val;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    char str1[100], str2[100], fin[200], temp[2];
    int arr[size];
    if(rank==0)
    {
        printf("Enter string 1: ");
        scanf("%s",str1);
        printf("Enter string 2 of same length: ");
        scanf("%s",str2);
    }
    MPI_Scatter(str1, 1, MPI_CHAR, &temp[0], 1, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(str2, 1, MPI_CHAR, &temp[1], 1, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Gather(temp, 2, MPI_CHAR, fin, 2, MPI_CHAR, 0, MPI_COMM_WORLD);
    if(rank==0)
    {
        printf("Interleaved string = %s\n", fin);
    }
    MPI_Finalize();
    return 0;
}
