#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define FIFO_NAME "single_proc_fif"
#define FIFO_MODE 0777
#define MAX 100
// Demonstration of a single named pipe in a single process

void printError(char *msg){
    perror(msg);
    exit(-1);
}

void *fifoWriter(void *arg){
    // To be called by a thread for simult operations
    const char * fifo = FIFO_NAME;
    int fd = open(fifo, O_WRONLY);
    char MSG[MAX] = "A message transferred to the same process through a pipe";

    write(fd, MSG, sizeof(MSG));
    printf("\nSuccessfully written to fifo : \n\n \"%s\"\n\n", MSG);

    close(fd);
    return NULL;
}


int main(){
    char RCV[MAX] = {0};

    // --------- Create a single named pipe ---------
    const char * fifo = FIFO_NAME;
    mkfifo(fifo, FIFO_MODE);

    //---------- Create a new thread so that read and write execute simult--------
    pthread_t thread;
    if (pthread_create(&thread, NULL, &fifoWriter, NULL) != 0)
        printError("Thread creation error");


    //----------Read from the pipe in the main thread ---------
    int fd = open(fifo, O_RDONLY);
    read(fd, RCV, MAX);

    printf("\nSuccessfully read from fifo : \n\n \"%s\"\n\n", RCV);
    close(fd);

    unlink(fifo);
    return 0;
}
