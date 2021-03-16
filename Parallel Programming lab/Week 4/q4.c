#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, arr[4][4], brr[4], ans[4];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank==0)
    {
    	printf("Enter values for 4X4 matrix:\n");
    	for(int i=0;i<4;i++)
    		for(int j=0;j<4;j++)
    			scanf("%d",&arr[i][j]);
    	printf("\nInput matrix:\n");
    	for(int i=0;i<4;i++)
    	{
    		for(int j=0;j<4;j++)
    			printf("%d ",arr[i][j]);
    		printf("\n");
    	}
        printf("Output matrix:\n");
    }

    MPI_Scatter(arr, 4, MPI_INT, brr, 4, MPI_INT, 0, MPI_COMM_WORLD);
    // printf("Row %d : ",rank);
    // for(int i=0;i<4;i++)
    //     printf("%d ",brr[i]);
    MPI_Scan(brr, ans, 4, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    for(int i=0;i<4;i++)
    	printf("%d ",ans[i]);
    printf("\n");
    MPI_Finalize();
    return 0;
}
