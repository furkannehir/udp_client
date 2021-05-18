#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <netinet/in.h>
#include "client.h"
#include "message.h"

#define PORT 8080

int main()
{
    srand ( time ( NULL));
    struct sockaddr_in servaddr;
    int sockfd = connectToServer(PORT, &servaddr);
    printf("Connection established.\n");
    MessageData msg;

    while (1)
    {
        //Data read from sensors
        msg.x = (double)rand()/RAND_MAX*20.0-10.0;
        msg.y = (double)rand()/RAND_MAX*20.0-10.0;
        printf("x: %.2f y: %.2f\n", msg.x, msg.y);
        sendMessage(sockfd, servaddr, msg);
        printf("Message sent.\n");
        sleep(3);
    }
}