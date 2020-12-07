#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#define MAX 80
#define PORT 8090
#define SA struct sockaddr

// Function designed for chat between client and server.
void servfunc(int sockfd, struct sockaddr_in cli)
{
	char buff[MAX];
	int n;
	// infinite loop for chat
	for (;;) {
		bzero(buff, MAX);

		// read the message from client and copy it in buffer
		read(sockfd, buff, sizeof(buff));
		if (strncmp("QUIT", buff, 4) == 0) {
			printf("Server Exit...\n");
			break;
		}
		// print buffer which contains the client contents
		printf("Client details: %s:%d\n", (char *)inet_ntoa(cli.sin_addr), cli.sin_port);
		printf("From client: %s", buff);
		
		//bzero(buff, sizeof(buff));
		// Read server message from keyboard in the buffer
		n=0;
		while (buff[n]!='\0')
		{
			if(buff[n] >= 'a' && buff[n] <= 'z') {
         		buff[n] = buff[n] -32;
         	}
         	n++;
		}
		// and send that buffer to client
		write(sockfd, buff, sizeof(buff));

		// if msg contains "Exit" then server exit and session ended.
		if (strncmp("QUIT", buff, 4) == 0) {
			printf("Server Exit...\n");
			break;
		}
	}
}

// Driver function
int main()
{
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created...\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded...\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening...\n");
	len = sizeof(cli);
	bzero(&cli, sizeof(cli));

	// Accept the data packet from client and verification
	//bzero(&cli, sizeof(cli));
	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("Server accept failed...\n");
		exit(0);
	}
	else
		printf("Server accept the client at %s:%d\n\n", (char *)inet_ntoa(cli.sin_addr), cli.sin_port);

	// Function for chatting between client and server
	servfunc(connfd, cli);

	// After sending exit message close the socket
	close(sockfd);
}