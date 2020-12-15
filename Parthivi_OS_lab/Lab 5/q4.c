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

int main(int argc, char *argv[])
{
	if(argc !=2)
	{
		printf("Invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	char ch;
	FILE *fr, *fw;
	fr = fopen(argv[1], "rb");
	if (fr == NULL)
		printf("Input binary file can't be opened\n");
	fw = fopen("q4.bin", "wb");
	if (fw == NULL)
		printf("Output binary file can't be opened\n");
	while((ch = fgetc(fr)) != EOF)
	{
		putc(ch, fw);
		printf("%c",ch);
	}
	fclose(fr);
	fclose(fw);
	return 0;
}