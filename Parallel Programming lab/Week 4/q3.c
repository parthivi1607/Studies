#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

void ErrorHandler(int error_code)
{
    if (error_code != MPI_SUCCESS)
    {
        char error_string[BUFSIZ];
        int length_of_error_string, error_class;
        MPI_Error_class(error_code, &error_class);
        MPI_Error_string(error_code, error_string, &length_of_error_string);
        printf("%d %s\n",  error_class, error_string);
   }
}

int main(int argc, char *argv[])
{
    int rank, size, error_code, arr[3][3], x, brr[3], num, count;
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    ErrorHandler(error_code);
    error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
    ErrorHandler(error_code);
    
    if(rank==0)
    {
    	printf("Enter values for 3X3 matrix:\n");
    	for(int i=0;i<3;i++)
    		for(int j=0;j<3;j++)
    			scanf("%d",&arr[i][j]);
    	printf("Enter value to be searched: ");
    	scanf("%d", &x);
    	printf("\nMatrix:\n");
    	for(int i=0;i<3;i++)
    	{
    		for(int j=0;j<3;j++)
    			printf("%d ",arr[i][j]);
    		printf("\n");
    	}
    }

    error_code = MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);
    ErrorHandler(error_code);
    error_code = MPI_Scatter(arr, 3, MPI_INT, brr, 3, MPI_INT, 0, MPI_COMM_WORLD);
    ErrorHandler(error_code);
    for(int i=0;i<3;i++)
    	count += (brr[i]==x);
    error_code = MPI_Reduce(&count, &num, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    ErrorHandler(error_code);
    
    if(rank==0)
    {
    	fprintf(stdout,"Element %d found %d times.\n",x,num);
    	fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}
