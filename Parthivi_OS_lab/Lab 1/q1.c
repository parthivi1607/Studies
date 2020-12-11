#define _POSIX_SOURCE
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		printf("2 values expected.\n");
	}
	else
	{
		printf("Searching for %s in %s\n", argv[2], argv[1]);
		int file = open(argv[1], O_RDONLY);
		if(file == -1)
    		perror("open() error");
  		else 
		{
    		char line[256], temp;
    		int flag=0, r, j=0;
    		while((r=read(file,&temp,sizeof(char)))!= 0)
        	{
            	if(temp!='\n')
            	{
                	line[j]=temp;
                	j++;
            	}
            	else
            	{
                	if(strstr(line,argv[2])!=NULL)
                	{
                		printf("A match found on line: %s\n", line); flag=1;
                	}
                	memset(line,0,sizeof(line));
                	j=0;
            	}

        	}
    		if(flag==0) printf("No matches.");
  		}
  		close(file);
	}
	return 0;
}