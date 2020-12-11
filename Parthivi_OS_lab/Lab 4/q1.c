#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h> 
#include <unistd.h>

int main()
{
	printf("Enter file name: ");
	char input[256];
	scanf("%s",input);
	struct stat sbuf;
	int ret = stat(input, &sbuf);
	if(ret)
	{
		perror("stat");
		return 1;
	}
	printf("Inode number: %ld\n", sbuf.st_ino);
	return 0;
}