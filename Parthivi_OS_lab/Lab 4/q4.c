#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h> 
#include <unistd.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		exit(-1);
	}
	int ret = symlink(argv[1], "./symlink_new");
	if(ret)
	{
		perror("symlink");
		return 1;
	} 
	else
	{
		ret = unlink(argv[1]);
		if(ret)
		{
			perror("unlink");
			return 2;
		}
	}
	return 0;
}