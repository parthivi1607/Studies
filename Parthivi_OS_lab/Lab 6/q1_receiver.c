#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>

#define SIZE 128

typedef struct message{
	long mtype;
	char c[SIZE];
} MESSAGE_t;

int reverseDigits(int n)
{
	int r = 0;
	while (n > 0)
	{
		r = r * 10 + n % 10;
		n = n / 10;
	}
	return r;
}

int isPalindrome(int n)
{
	int r = reverseDigits(n);
	if (r == n)
		return 1;
	else
		return 0;
}

int main (int argc, char const * argv[] )
{
	int qt;
	MESSAGE_t message;
	if ((qt = msgget((key_t)1271, IPC_CREAT | 0666)) < 0)
	{
		perror("Error in msgget()");
		exit(EXIT_FAILURE);
	}
	printf("Message queue created.\n");
	if (msgrcv(qt, &message, sizeof(MESSAGE_t), 0, 0) < 0)
	{
		perror("Error in msgrcv()");
		exit(EXIT_FAILURE);
	}

	printf("Successfully received number: %s\n", message.c);
	int num = atoi(message.c);
	if (isPalindrome(num))
		printf("The number is a palindrome\n");
	else
		printf("The number is not a palindrome\n");


	if(msgctl(qt, IPC_RMID, NULL)==-1){
		fprintf(stderr, "IPC_RMID failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}