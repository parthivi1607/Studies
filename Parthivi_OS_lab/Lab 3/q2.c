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
		execlp("/home/student/Parthivi_OS_lab/Lab 3/q1","./q1",NULL);
	}
	else
	{
		wait(NULL);
		printf("Child complete\n");
		exit(0);
	}
	return 0;
}