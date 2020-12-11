#define _POSIX_SOURCE
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int fd, count=0;
	for(int i=1;i<argc;i++)
    {
        if((fd = open(argv[i],O_RDONLY))==-1)
            perror("open() error");
        else
        {
            char line[256], temp;
            int r, j=0;
            while((r=read(fd,&temp,sizeof(char)))!= 0)
            {
                if(temp!='\n')
                {
                    line[j]=temp;
                    j++;
                }
                else
                {
                    count++;
                    if(count<=20)
                    {
                        printf("%s\n",line);
                    }
                    else
                    {
                        printf("Enter a key to see more lines: ");
                        char c = getchar();
                        count=0;
                    }
                    memset(line,0,sizeof(line));
                    j=0;
                }
            }
        }
        close(fd);
    }
	return 0;
}