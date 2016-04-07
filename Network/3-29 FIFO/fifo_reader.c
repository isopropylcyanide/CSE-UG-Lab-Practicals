#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FIFO_NAME "aman_fifo_files"
#define FIFO_MODE 0666
#define MAX 100

// Two demonstrate a named pipe and message tranfer between two unrelated processes
// This program creates a process B that reads from a named pipe written by another process A

int main(){
    //Prepare the message to send
    char RCV[MAX] = {0};

    //open a named named pipe
    const char * fifo = FIFO_NAME;

    //Read from the special fifo file
    int fd = open(fifo, O_RDONLY);
    while (1) {
        if (read(fd, RCV, MAX) > 0){
            printf("\nSuccessfully read from fifo : \n\n \"%s\"\n\n", RCV);
            break;
        }
        else {
            perror("Read error from fifo");
            return -1;
        }
    }

    close(fd);

    return 0;
}
