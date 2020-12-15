#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int fd[2];
	pid_t pid;
	char buf[1024];
	if(argc!=2)
	{
		printf("Invalid no. of arguments\n");
		exit(EXIT_FAILURE);
	}
	if(pipe(fd)==-1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if(pid==-1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid==0) //child process
	{
		char ch;
		FILE *fw;
		fw = fopen("q4.bin", "wb");
		if (fw == NULL)
			printf("Output binary file can't be opened\n");
		printf("Reading in child...\n");
		close(fd[1]); //close unused write end
		while(read(fd[0], &buf, strlen(buf))>0)
		{
			fputs(buf, fw);
		}
		close(fd[0]);
		printf("Child ended\n");
		fclose(fw);
		exit(EXIT_SUCCESS);
	}
	else //parent process
	{
		char ch;
		FILE *fr = fopen(argv[1], "rb");
		if (fr == NULL)
			printf("Input binary file can't be opened\n");
		printf("Writing in parent...\n");
		close(fd[0]); //close unused read end
		while(fgets(buf, 1024, fr) !=NULL)
		{
			write(fd[1], buf, strlen(buf));
		}
		close(fd[1]); //reader will see EOF
		wait(NULL); //wait for child to terminate
		printf("Parent ended\n");
		fclose(fr);
		exit(EXIT_SUCCESS);
	}
	return 0;
}