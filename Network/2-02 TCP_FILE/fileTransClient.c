#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
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

    // A socket address structure to hold in the socket
    struct sockaddr_in serv_addr = {0};

    // Create TCP Socket: mention domain, stream/datagram and default protocol
    sockFd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockFd < 0){
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

    if( connect(sockFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
       printf("\n Error : Connect Failed \n");
       return 1;
    }

    // Read from input and write to socket
    fprintf(stdout, "\n Storing file received from server: %s \n\n", inet_ntoa(serv_addr.sin_addr));

    FILE * fp = fopen(outputFile, "w");
    assert(fp);

    // Read message from server
    n = read(sockFd, recvBuff, MAX);
    // Write the message received from server onto file
    fwrite(recvBuff, 1, n, fp);

    // Also display file contents
    write(0, recvBuff, n);

    // Close file
    fclose(fp);
    return 0;
}









//
