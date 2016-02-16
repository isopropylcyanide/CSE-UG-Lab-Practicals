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
    char recvBuff[MAX] = {' '};
    char reversedStr[MAX] = {' '};


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

    while(true){
        // accept incoming client connections to the given socket
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

        // Read the message from the socket into a string
        int readChar = read(connfd, recvBuff, MAX), count = 0;

        bzero(reversedStr, MAX);
        write(0, recvBuff, readChar);

        for (int i = readChar - 1; i >= 0; i--)
            reversedStr[count ++] = recvBuff[i];

        write(connfd, reversedStr, readChar);
        close(connfd);
        sleep(1);
     }
}


















//
