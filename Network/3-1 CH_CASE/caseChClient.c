#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define localhost "127.70.0.10"
#define MAX 1024
#define PORT 25000

// Program to send a string to server. Return the Upper case form of the string

int main(){
    // Set up client sockets, character buffers
    int sockfd = 0, n = 0;

    // Read input String from the user
    printf("\n Enter String: ");
    char sendBuff[MAX] = {' '}, recvBuff[MAX] = {' '};
    fgets(sendBuff, MAX, stdin);

    // A socket address structure to hold in the socket
    struct sockaddr_in serv_addr = {0};

    // mention domain, stream/datagram and default protocol
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        perror("\n Error : Could not create socket \n");
        return 1;
    }

    // initialise members of the socket's address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Read from input and write to socket

    if(inet_pton(AF_INET, localhost, &serv_addr.sin_addr)<=0){
        printf("\n inet_pton error occured\n");
        return 1;
    }


    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
       printf("\n Error : Connect Failed \n");
       return 1;
    }

    printf ("\n Sending : %s" , sendBuff);
    write(sockfd, sendBuff, MAX);

    n = read(sockfd, recvBuff, MAX);
    if (n < 0)
        perror("Error Reading value from server");

    printf ("\n Receiving: %s", recvBuff);

    printf("\n");
    close(sockfd);
    return 0;
}
