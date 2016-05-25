#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/utsname.h>

#define MAX 100

void resolveName(char *host_name){
    // Given a url in human readable format, convert it into byte order IP
    struct hostent *host;
    struct in_addr **h_addr;


    if ((host = gethostbyname(host_name)) == NULL){
        perror(" Couldn't resolve hostname");
        return;
    }

    h_addr = (struct in_addr **) host -> h_addr_list;
    for (int i = 0; h_addr[i] != NULL; i++)
        printf(" %s resolved to: %s\n\n", host_name, inet_ntoa(*h_addr[i]));
}

int main(){

    struct utsname myName;
    if (uname(&myName) == 0){
        printf("Name: %s\n", myName.machine );
        printf("Node: %s\n", myName.nodename);
        printf("Rele: %s\n", myName.release);
        printf("SysN: %s\n", myName.sysname);
        printf("Vers: %s\n", myName.version);
    }

    char host_name[MAX];

    printf("\n Enter host name to resolve: ");
    scanf("%s", host_name);

    resolveName(host_name);
    return 0;
}
