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
}MESSAGE_t;

int main (int argc, char const * argv[])
{
	int qt;
	MESSAGE_t msg;
	if((qt = msgget((key_t)1271, 0)) < 0)
	{ 
		perror("Error in msgget()");
		exit(EXIT_FAILURE);
	}
	printf("Enter the number: ");
	fgets(msg.c, SIZE, stdin);
	msg.mtype = 1;
	if(msgsnd(qt, &msg, sizeof(MESSAGE_t), 0) < 0)
	{
		perror("Error in msgsnd()");
		exit(EXIT_FAILURE);
	}
	printf("Successfully sent.\n");
	return 0;
}