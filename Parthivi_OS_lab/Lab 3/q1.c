#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *msg;
	int n, status;
	printf("Fork program starting\n");
	pid_t pid = fork();
	switch(pid)
	{
		case -1:
			perror("Fork failed");
			exit(1);
		case 0:
			msg = "Child process";
			n=5; break;
		default:
			msg = "Parent process";
			n=3; break;
	}
	if(pid!=0)
	{
		wait(&status);
		printf("Child returned: %d\n", status);
	}
	for(;n>0;n--)
	{
		puts(msg);
		sleep(1);
	}
	return 0;
}