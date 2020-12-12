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
void T();
void Tprime();

void S()
{
	if(str[curr]=='a')
	{
		curr++;
		return;
	}
	else if(str[curr]=='>')
	{
		curr++;
		return;
	}
	else if(str[curr]=='(')
	{
		curr++;
		T();
		if(str[curr]==')')
		{
			curr++;
			return;
		}
		else invalid();
	}
	else invalid();
}

void T()
{
	S();
	Tprime();
}

void Tprime()
{
	if(str[curr]==',')
	{
		curr++;
		S();
		Tprime();
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