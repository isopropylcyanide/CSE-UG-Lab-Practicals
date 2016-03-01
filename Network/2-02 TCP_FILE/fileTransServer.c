#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <stdbool.h>
#include <assert.h>

#define MAX 1024
#define PORT 25000
#define MAX_BACKLOG 10
#define SERVER_INPUT_FILE "inputServer"

// Send a given input file to every client that wishes to connect

int main(){
    // Create a fd for server and one for client
    int sockFd = 0, clientFd = 0, readChar;

    // A socket address structure to hold in the socket
    struct sockaddr_in serv_addr = {0};

    // String to hold input file line by line for client
    char sendBuff[MAX];

    // Creates a TCP socket i.e file descriptor within the process table
    sockFd = socket(AF_INET, SOCK_STREAM, 0);

    // initialise members of the socket's address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    // Assign protocol to a socket :=
    bind(sockFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // listen for incoming connections with a specified backlog queue
    listen(sockFd, MAX_BACKLOG);

    // read input from file once
    FILE *fp = fopen(SERVER_INPUT_FILE, "r");
    assert (fp);
    while (!feof(fp))
        readChar = fread(sendBuff, 1, MAX, fp);

    fclose(fp);

    while(true){
        // Socket address structure to hold the client socket
        struct sockaddr_in addr;
        socklen_t addr_size = sizeof(struct sockaddr_in);

        // accept incoming client connections to the given socket descriptor clientFd
        clientFd = accept(sockFd, (struct sockaddr *)&addr, &addr_size);
        fprintf(stdout, "\nA new client has connected. Sending file\n");
        fprintf(stdout, "IP Address: %s\n", inet_ntoa(addr.sin_addr) );

        write(clientFd, sendBuff, readChar);
        close(clientFd);
        sleep(1);
    }

    return 0;
}












//
