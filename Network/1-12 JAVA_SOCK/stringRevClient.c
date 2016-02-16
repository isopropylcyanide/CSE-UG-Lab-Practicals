#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define localhost "127.0.0.10"
#define MAX 1024
#define PORT 25000


int main(){
    // Set up client sockets, buffers and socket structure
    int sockfd = 0, n = 0;
    char recvBuff[MAX] = {' '};
    char sendBuff[MAX] = {' '};
    struct sockaddr_in serv_addr = {0};

    // mention domain, stream/datagram and default protocol
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("\n Error : Could not create socket \n");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
       printf("\n Error : Connect Failed \n");
       return 1;
    }

    // Read from input and write to socket
    fprintf(stdout, "\n Enter the string to reverse:  ");
    fgets(sendBuff, MAX, stdin);
    printf("\n Writing to server socket:  %s", sendBuff);

    n = write(sockfd, sendBuff, strlen(sendBuff)) ;
    if(n < 0)
        perror("\n Write error \n");

    n = read(sockfd, recvBuff, MAX);
    printf(" Received from server sock: ");

    for (int i = 0; i < n; i++)
        printf("%c",recvBuff[i]);

    printf("\n");

    return 0;
}
