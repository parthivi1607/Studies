#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 5000
#define MAXLINE 1000

//Driver code
int main()
{
	char buffer[100];
	int sockfd, n,len, r, c;
	struct sockaddr_in servaddr, cliaddr;
	
	// clear servaddr
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	servaddr.sin_family = AF_INET;
	
	// create datagram socket
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	printf("Enter number of rows of matrix : ");
	scanf("%d",&r);
	sendto(sockfd, r, MAXLINE, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));

	for(int i=0;i<r;i++)
	{
		printf("Enter number of columns in row %d : ", (i+1));
		scanf("%d",&c);
		sendto(sockfd, r, MAXLINE, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));

		int *arr = calloc(c, sizeof(int));
		printf("Enter row values : \n");
		for(int j=0;j<c;j++)
			scanf("%d", &arr[j]);
		sendto(sockfd, arr, MAXLINE, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
	}

	// close the descriptor
	close(sockfd);
}