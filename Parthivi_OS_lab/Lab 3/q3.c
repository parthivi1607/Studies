#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid = fork();
	if(pid<0)
	{
		printf("Fork failed\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("In child:\n");
		printf("Child process pid = %d\n", getpid());
		printf("Parent process pid = %d\n", getppid());
	}
	else
	{
		wait(NULL);
		printf("\nIn parent:\n");
		printf("Parent process pid = %d\n", getpid());
		printf("Child process pid = %d\n", pid);
	}
	return 0;
}