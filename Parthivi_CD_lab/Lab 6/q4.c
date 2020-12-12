#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int curr=0;
char str[1024];

void invalid()
{
	printf("ERROR!\n");
	exit(1);
}

void valid()
{
	printf("SUCCESS!\n");
	exit(0);
}

void S();
void L();
void Lprime();

void S()
{
	if(str[curr]=='a')
	{
		curr++;
		return;
	}
	else if(str[curr]=='(')
	{
		curr++;
		L();
		if(str[curr]==')')
		{
			curr++;
			return;
		}
		else invalid();
	}
	else invalid();
}

void L()
{
	S(); Lprime();
}

void Lprime()
{
	if(str[curr]==',')
	{
		curr++;
		S(); Lprime();
	}
}

void main()
{
	printf("Enter a string: ");
	scanf("%s", str);
	S();
	if(str[curr]=='$') valid();
	else invalid();
}