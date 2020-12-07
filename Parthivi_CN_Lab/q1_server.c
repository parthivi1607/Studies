#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 5000
#define MAXLINE 1000

// Server code
int main()
{
	char buffer[100];
	int servsockfd, len,n, r, c;
	struct sockaddr_in servaddr, cliaddr;
	bzero(&servaddr, sizeof(servaddr));

	// Create a UDP Socket
	servsockfd = socket(AF_INET, SOCK_DGRAM, 0);		
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	servaddr.sin_family = AF_INET;

	// bind server address to socket descriptor
	bind(servsockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	len = sizeof(cliaddr); 

	recvfrom(servsockfd, r, sizeof(r),0, (struct sockaddr*)&cliaddr,&len);
	
	//receive the datagram
	for(;;)
	{
		n = recvfrom(servsockfd, buffer, sizeof(buffer),0, (struct sockaddr*)&cliaddr,&len);
		buffer[n] = '\0';
		for(int j=0;;j++)
			printf("%d ",buffer[j]);
		printf("\n");
	}

	// close the descriptor
	close(servsockfd);
}