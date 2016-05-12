#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>1
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <arpa/inet.h>

#define localhost "127.0.0.10"
#define outputFile "ServerOutput"
#define MAX 1024
#define PORT 25000

// Connect to the server at the given location and create a file mentioning its inputs


int main(){
    // Set up client sockets, character buffers
    int sockFd = 0, n = 0;
    char recvBuff[MAX] = {' '};
    char sendBuff[] = "Hello Server. I need the file";

    // A socket address structure to hold in the socket
    struct sockaddr_in serv_addr = {0};
    socklen_t serv_addr_size = sizeof(struct sockaddr_in);

    // Create TCP Socket: mention domain, stream/datagram and default protocol

    if((sockFd = socket(AF_INET, SOCK_DGRAM, 0))< 0){
        perror("\n Error : Could not create socket \n");
        return 1;
    }

    // initialise members of the socket's address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, localhost, &serv_addr.sin_addr) <= 0){
        printf("\n inet_pton error occured\n");
        return 1;
    }

    FILE * fp = fopen(outputFile, "w");
    assert(fp);

    //Send a sendBuff to server demanding the file as an input
    sendto(sockFd, sendBuff, strlen(sendBuff), 0, (struct sockaddr *)&serv_addr, serv_addr_size);

    // Read sendBuff from server
    if ((n = recvfrom(sockFd, recvBuff, MAX, 0, (struct sockaddr *)&serv_addr, &serv_addr_size)) != -1){
        // Read from input and write to socket
        fprintf(stdout, "\n Storing file received from server: %s \n\n", inet_ntoa(serv_addr.sin_addr));
        // Write the sendBuff received from server onto file
        fprintf(stdout, "\n Received file from server: \n\n %s \n", recvBuff);
        fwrite(recvBuff, 1, n, fp);
    }

    // Close file
    close(sockFd);
    fclose(fp);
    return 0;
}









//
