#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#define PORT 5000
#define MAXLINE 1000

// Driver code
int main()
{
	char buffer[100];
	int sockfd, n, len;
	struct sockaddr_in servaddr, cliaddr;
	// clear servaddr
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	servaddr.sin_family = AF_INET;
	// create datagram socket
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	int matrix[3][3];
	for (int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			matrix[i][j] = i*j;
		sendto(sockfd, matrix[i], 3*sizeof(int), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
	}

	len = sizeof(cliaddr);
	// waiting for response
	n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cliaddr, &len );
	buffer[n] = '\0';
	printf("Message from server is %s \n", buffer);

	// close the descriptor
	close(sockfd);
}