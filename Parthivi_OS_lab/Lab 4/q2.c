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
	int n = stat(input, &sbuf);
	if(n)
	{
		perror("stat");
		return 1;
	}
	printf("ID of device containing file: %ld\n", sbuf.st_dev);
	printf("Inode no.: %ld\n", sbuf.st_ino);
	printf("No. of hard links: %ld\n", sbuf.st_nlink);
	printf("User ID of owner: %d\n", sbuf.st_uid);
	printf("Size: %ld bytes\n", sbuf.st_size);
	return 0;
}