#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct message {
	long int msgType;
	char msgData[BUFSIZ];
}MESSAGE;

int main()
{
	MESSAGE m1;
	long int msg_to_recieve = 0;
	int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);

	if (msgid == -1) {
		printf("msgget failed with error: %d\n", errno);
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		if (msgrcv(msgid, (void*)&m1, BUFSIZ, msg_to_recieve, 0) == -1)
		{
			printf("msgrcv failed with error: %d\n", errno);
			exit(EXIT_FAILURE);
		}
		if (strncmp(m1.msgData, "quit", 4) == 0)
			break;

		char rev[BUFSIZ];
		int i;
		for (i = 0; m1.msgData[i] != '\n'; i++);

		for (int j = 0; j < i; j++)
			rev[j] = m1.msgData[i - j - 1];

		rev[i] = '\0';
		m1.msgData[i] = '\0';

		if (strcmp(m1.msgData, rev) == 0)
			printf("%s is a Palindrome\n", m1.msgData);
		else 
			printf("%s is not a Palindrome\n", m1.msgData);
	}

	if (msgctl(msgid, IPC_RMID, 0) == -1)
	{
		perror("msgctl(IPC_RMID) failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}