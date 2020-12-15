#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

typedef struct message {
	long int msgType;
	char msgData[BUFSIZ];
}MESSAGE;

int main()
{
	MESSAGE m1;
	char buffer[BUFSIZ];
	int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	
	if (msgid == -1)
	{
		printf("msgget failed with error: %d\n", errno);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		printf("Enter a number: ");
		fgets(buffer, BUFSIZ, stdin);
		m1.msgType = 1;
		strcpy(m1.msgData, buffer);
		
		if (msgsnd(msgid, (void *)&m1, MAX_TEXT, 0) == -1)
		{
			perror("msgsnd failed\n");
			exit(EXIT_FAILURE);
		}
		if (strncmp(buffer, "quit", 3) == 0)
			break;
	}
	exit(EXIT_SUCCESS);
}