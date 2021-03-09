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
    char str[100], ch;
    int arr[size];
    if(rank==0)
    {
        printf("Enter a string: ");
        scanf("%s",str);
    }
    MPI_Scatter(str, 1, MPI_CHAR, &ch, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
    {
    	if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
    	{
    		printf("Process %d says %c is a vowel.\n", rank, ch);
    		val=0;
    	}
    	else
    	{
    		printf("Process %d says %c is not a vowel.\n", rank, ch);
    		val=1;
    	}
    }
    MPI_Gather(&val, 1, MPI_INT, arr, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if(rank==0)
    {
        int sum=0;
        for(int i=0;i<size;i++)
        {
        	sum += arr[i];
        	printf("Process %d found %d non-vowel\n", i, arr[i]);
        }
        printf("No. of non-vowels = %d\n", sum);
    }
    MPI_Finalize();
    return 0;
}
