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
	int open_mode = O_RDONLY;
	int bytes_read = 0;
	int buf=0;

	printf("Process %d opening read-only FIFO\n", getpid());
	pipe_fd = open(FIFO_NAME, open_mode);

	if(pipe_fd!=-1)
	{
		res = read(pipe_fd, &buf, sizeof(int));
		while(res>0)
		{
			printf("%d\n", buf);
			bytes_read += res;
			res = read(pipe_fd, &buf, sizeof(int));
		}
		close(pipe_fd);
	}
	else
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	printf("Process %d finished\nBytes read = %d\n", getpid(), bytes_read);
	exit(EXIT_SUCCESS);
	return 0;
}