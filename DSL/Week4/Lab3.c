#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int n)
{
	int l=0;
	if(n==0) return 0;
	else if(n==1) return 1;
	else
	{
		l=fibonacci(n-1)+fibonacci(n-2);
	}
	return l;
}

void copystring(char s1[], char s2[], int i)
{
	s2[i]=s1[i];
	if(s1[i]=='\0')return;
	copystring(s1,s2,++i);
}

void palindrome(char *s1, char *s2, int l)
{
	if(l==0)
	{
		*s2 = '\0';
		return;
	}
	else
	{
		char *p;
		p=s1+l-1;
		*s2 = *p;
		palindrome(s1,s2+1,--l);
	}
}

void towerofhanoi(int n, char s, char t, char d, int *m)
{
	if(n==1)
	{
		printf("Move disk 1 from %c to %c\n",s,d);
		(*m)++;
		return;
	}
	towerofhanoi(n-1,s,d,t,m);
	(*m)++;
	printf("Move disk %d from %c to %c\n",n,s,d);
	towerofhanoi(n-1,t,s,d,m);
}

int main()
{
	int n;
	int num;
	char s1[100];
	char s2[100];
	int i,c=0,flag=0;
	printf("Enter option : \n");
	printf("1. Fibonacci series\n");
	printf("2. Copy a string to another string\n");
	printf("3. Check if string is palindrome\n");
	printf("4. Tower of Hanoi\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
		printf("Enter no. of terms : ");
		scanf("%d",&num);
		for(int i=0;i<num;i++)
			printf("%d ",fibonacci(i));
		printf("\n");
		break;

		case 2:
		printf("Enter string 1 : ");
		scanf("%s",s1);
		printf("Copied string 2 : ");
		copystring(s1,s2,0);
		for(i=0;s2[i]!='\0';i++) printf("%c",s2[i]);
		printf("\n");
		break;

		case 3:
		printf("Enter string 1 : ");
		scanf("%s",s1);
		for(i=0;s1[i]!='\0';i++) c++;
		palindrome(s1,s2,c);
		for(i=0;i<c;i++)
		{
			if(s1[i]==s2[i]) flag=1;
			else
			{
				flag=0; break;
			}
		}
		if(flag==1) printf("Palindrome\n");
		else printf("Not palindrome\n");
		break;

		case 4:
		printf("Enter no. of disks : ");
		scanf("%d",&num);
		towerofhanoi(num,'A','B','C',&c);
		printf("No. of moves = %d\n",c);
		break;

		default:
		printf("Invalid\n");
	}
	return 0;
}