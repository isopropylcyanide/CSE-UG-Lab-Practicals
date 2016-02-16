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

#define MAX 1024
#define PORT 25000
#define MAX_BACKLOG 10


int main(){
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr = {0};

    char recvBuff[MAX] = {' '};
    char reversedStr[MAX] = {' '};

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(listenfd, MAX_BACKLOG);

    while(1){
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
        int readChar = read(connfd, recvBuff, MAX), count = 0;

        bzero(reversedStr, MAX);
        fprintf(stdout,"\n Received from client: %s",recvBuff );
        for (int i = readChar - 1; i >= 0; i--)
            reversedStr[count ++] = recvBuff[i];

        write(connfd, reversedStr, readChar);

        close(connfd);
     }
}


















//
