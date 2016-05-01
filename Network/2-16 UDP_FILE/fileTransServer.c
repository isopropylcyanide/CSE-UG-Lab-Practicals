#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <assert.h>

#define MAX 1024
#define PORT 25000
#define MAX_BACKLOG 10
#define SERVER_INPUT_FILE "inputServer"

// Send a given input file to every client that wishes to connect

int main(){
    // Create a fd for server and one for client
    int sockFd;

    // A socket address structure to hold in the socket
    struct sockaddr_in serv_addr = {0};

    // String to hold input file line by line for client and the client's message
    char sendBuff[MAX], recvBuff[MAX];

    // Creates a TCP socket i.e file descriptor within the process table
    sockFd = socket(AF_INET, SOCK_DGRAM, 0);

    // initialise members of the socket's address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    // Assign protocol to a socket :=
    bind(sockFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    FILE *fp = fopen(SERVER_INPUT_FILE, "r");
    int readChar;
    assert (fp);

    while (!feof(fp))
        readChar = fread(sendBuff, 1, MAX, fp);

    fclose(fp);
    struct sockaddr_in addr;
    socklen_t addr_size = sizeof(addr);

    while(true){
        // Socket address structure to hold the client socket

        fprintf(stdout, "Waiting for client\n");

        if (recvfrom(sockFd, recvBuff, MAX, 0, (struct sockaddr *)&addr, &addr_size) != -1){
            fprintf(stdout, "\n Client has connected. It says: %s \n", recvBuff);
            fprintf(stdout, "\n Sending File => to client : %s \n",inet_ntoa(addr.sin_addr) );
            sendto(sockFd, sendBuff, readChar, 0, (struct sockaddr *)&addr, sizeof(addr));
        }

        sleep(1);
    }
    close(sockFd);

    return 0;
}












//
