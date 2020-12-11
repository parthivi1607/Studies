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
		fprintf(stderr, "Fork failed\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("Child process\n");
		exit(0);
	}
	else
	{
		sleep(20);
		printf("Parent process\n");
	}
	return 0;
}