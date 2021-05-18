#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
#include "client.h"


int connectToServer(int port, struct sockaddr_in * servaddr)
{
    int sockfd;
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    memset(servaddr, 0, sizeof(*servaddr));
    servaddr->sin_family = AF_INET;
    servaddr->sin_port = htons(port);
    if (inet_aton(SERVER , &(servaddr->sin_addr)) == 0) 
	{
		fprintf(stderr, "inet_aton() failed\n");
		exit(1);
	}
    return sockfd;
}

int sendMessage(int sockfd, struct sockaddr_in servaddr, MessageData msg)
{
    return sendto(sockfd, (const char *)&msg, sizeof(msg), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
}

int closeConnection(int sockfd)
{
    close(sockfd);
}