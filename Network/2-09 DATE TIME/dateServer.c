#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <time.h>
#include <stdbool.h>

#define MAX 1024
#define PORT 25000
#define MAX_BACKLOG 10


int main(){
    // fd for server side and one fd for the client side
    int listenfd = 0, connfd = 0;

    // A socket address structure to hold in the socket
    struct sockaddr_in serv_addr = {0};

    // Strings to manipulate incoming and outgoing data
    char sendBuff[MAX] = {' '};

    // Creates a socket i.e file descriptor within the process table
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    // initialise members of the socket's address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    // Assign protocol to a socket :=
    bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // listen for incoming connections with a specified backlog queue
    listen(listenfd, MAX_BACKLOG);

    time_t new_time = time(NULL);

    while(true){
        // accept incoming client connections to the given socket
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

        // Read the message from the socket into a string
        snprintf(sendBuff, MAX, "%s", ctime(&new_time) );
        printf("\n Client connected. Sending Time : %s\n", sendBuff);
        write(connfd, sendBuff, strlen(sendBuff));

        close(connfd);
        sleep(1);
     }
}


















//
