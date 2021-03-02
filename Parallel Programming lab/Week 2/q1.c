#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int rank;
	char str[100];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status status;
	if(rank==0)
	{
		printf("Enter a word in master process: ");
		scanf("%s", str);
		MPI_Ssend(str,strlen(str),MPI_CHAR,1,0,MPI_COMM_WORLD);
		printf("Process 0 has sent word.\n");
		MPI_Recv(str,100,MPI_CHAR,1,0,MPI_COMM_WORLD,&status);
		printf("Process 0 has received modified word - %s.\n",str);
	}
	else
	{
		MPI_Recv(str,100,MPI_CHAR,0,0,MPI_COMM_WORLD,&status);
		printf("Process 1 has received word - %s.\n",str);
		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]>='A' && str[i]<='Z') str[i] += 32;
			else if(str[i]>='a' && str[i]<='z') str[i] -=32;
		}
		MPI_Ssend(str,strlen(str),MPI_CHAR,0,0,MPI_COMM_WORLD);
		printf("Process 1 has sent modified word.\n");
	}
	MPI_Finalize();
	return 0;
}