#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE *f;
	printf("Enter file name: ");
	char input[256];
	scanf("%s",input);
	f = fopen(input, "r");
	if (f == NULL)
	{
		printf("Cannot open file\n");
		exit(0); 
	}

    char c;
	char keyw[20][20] = {"const", "bool", "char", "int","float", "double","return", "for", "while", "do", "switch","if", "else","case", "break","printf"};

	printf("Keywords are:\n");
	while((c=fgetc(f)) !=EOF)
	{
		if(isalpha(c))
		{
			char buf[100];
			int x=0;
			while(isalpha(c))
			{
				buf[x++]=c;
				c=getc(f);
			}
			if(c==' '||c=='\t'||c=='\n'||c=='('||c=='{'||c==';')
			{
				buf[x]='\0';
				for(int i=0;i<20;i++)
				{
					if(strcmp(buf,keyw[i])==0)
					{
						for(int j=0;j<x;j++)
							printf("%c",toupper(buf[j]));
						printf("\n");
						break;
					}
				}
			}
			else
			{
				// printf("entered not blank  %c\n",c);
				while(c!=' ' && c!='\t' && c!='\n' && c!='(' && c!='{' && c!=';' && c!=EOF)
					c=getc(f);
			}			
		}
		else
		{
			while(c!=' ' && c!='\t' && c!='\n' && c!='(' && c!='{' && c!=';' && c!=EOF)
				c=getc(f);
		}	
	}
	fclose(f);
	return 0;
}