#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include <string.h>
#define PORT 5000
#define MAXLINE 1000
// Server code
int main()
{
	int buffer[100];
	char buff[100];
	int servsockfd, len, n;
	struct sockaddr_in servaddr, cliaddr;
	bzero(&servaddr, sizeof(servaddr));

	// Create a UDP Socket
	servsockfd = socket(AF_INET, SOCK_DGRAM, 0);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	servaddr.sin_family = AF_INET;

	// bind server address to socket descriptor
	bind(servsockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

	//receive the datagram
	int matrix[3][3];
	len = sizeof(cliaddr); 
	for (int i = 0; i < 3; i++) {
		n = recvfrom(servsockfd, buffer, 3*sizeof(int), 0, (struct sockaddr*)&cliaddr, &len);
		for (int j = 0; j < 3; ++j) matrix[i][j] = buffer[j];
	}
	for (int i = 0; i < 3; i++) {
		for ( int j = 0; j < 3; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	//Echoing back to the client
	strcpy(buff,"Matrix recieved");
	sendto(servsockfd, buff, sizeof(buff), 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr));
	
	// close the descriptor
	close(servsockfd);
}