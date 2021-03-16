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
    int rank, size, error_code;
    float pi, area;
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    ErrorHandler(error_code);
    error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
    ErrorHandler(error_code);
    float x = (float)(rank+1)/size;
    float y = 4.0/(1 + x*x);
    area = (1.0/size) * y;
    error_code = MPI_Reduce(&area, &pi, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
    ErrorHandler(error_code);
    if(rank==0)
    {
    	fprintf(stdout, "Value of pi = %f\n", pi);
		fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}