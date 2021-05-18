#ifndef CLIENT_H
#define CLIENT_H

#include "message.h"

#define SERVER "127.0.0.1"
#define MAXLINE 1024

int connectToServer(int port, struct sockaddr_in * servaddr);
int sendMessage(int sockfd, struct sockaddr_in servaddr, MessageData msg);
int closeConnection(int sockfd);

#endif