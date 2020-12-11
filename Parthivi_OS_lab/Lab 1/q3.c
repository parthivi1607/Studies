#define _POSIX_SOURCE
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	char c = 'a';
	int i = -7;
	unsigned int u = 5;
	float f = 9.56;
	double d = 45.89023761;
	char *str = "Party";
	printf("Character : %c\n", c);
	printf("Integer : %d\n",i);
    printf("Unsigned Integer : %u\n",u);
    printf("Float : %f\n",f);
    printf("Double : %lf\n",d);
    printf("String : %s\n",str);
    errno = EPERM;
    printf("\nError No. : %m\n");
	return 0;
}