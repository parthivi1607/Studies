#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>

#define FIFO_NAME "/tmp/my_fifo"

int main()
{
	int pipe_fd;
	int res;
	int open_mode = O_WRONLY;
	int bytes_sent = 0;

	if(access(FIFO_NAME, F_OK)==-1)
	{
		res = mkfifo(FIFO_NAME, 0777);
		if(res!=0)
		{
			fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
		printf("Fifo created\n");
	}
	printf("Process %d opening write-only FIFO\n", getpid());
	pipe_fd = open(FIFO_NAME, open_mode);

	if(pipe_fd!=-1)
	{
		char ch;
		FILE *fr = fopen("input.txt", "r");
		if (fr == NULL)
			printf("Input binary file can't be opened\n");
		while((ch = getc(fr)) != EOF);
		{
			printf("%c",ch);
			res = write(pipe_fd, &ch, sizeof(char));
			if(res==-1)
			{
				fprintf(stderr, "Write error on pipe\n");
				exit(EXIT_FAILURE);
			}
			bytes_sent += res;
		}
		fclose(fr);
		close(pipe_fd);
	}
	else
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	printf("Process %d finished\nBytes sent = %d\n", getpid(), bytes_sent);
	exit(EXIT_SUCCESS);
	return 0;
}