#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FIFO_NAME "aman_fifo_files"
#define FIFO_MODE 0666
#define MAX 100

// Two demonstrate a named pipe and message tranfer between two unrelated processes
// This program creates a process A that writes to a pipe for another process C

int main(){
    //Prepare the message to send
    char MSG[MAX] = "A message from an unrelated process using FIFO-A";

    //create a named pipe
    const char * fifo = FIFO_NAME;
    mkfifo(fifo, FIFO_MODE);

    //Write to the special fifo file
    int fd = open(fifo, O_WRONLY);
    if (write(fd, MSG, sizeof(MSG)) < 0){
        perror("Writing to named pipe error");
        return -1;
    }

    printf("\nSuccessfully written to fifo : \n\n \"%s\"\n\n", MSG);

    close(fd);
    unlink(fifo);

    return 0;
}
