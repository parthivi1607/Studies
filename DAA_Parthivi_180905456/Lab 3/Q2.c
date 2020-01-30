#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
    int opcount=0;
  
    for (int i = 0; i <= N - M; i++)
    { 
        int j;
        for (j = 0; j < M; j++)
        {
        	opcount++;
        	if (txt[i + j] != pat[j])
        		break;
        }

        if (j == M)
        {
        	printf("Pattern found at index %d \n", i);
        	break;
        }
    } 
    printf("Opcount = %d\n",opcount);
} 
  
int main() 
{ 
    printf("Enter string : ");
    char txt[100];
    gets(txt);
    printf("Enter string to search : ");
    char pat[100];
    gets(pat);
    search(pat, txt); 
    return 0; 
} 