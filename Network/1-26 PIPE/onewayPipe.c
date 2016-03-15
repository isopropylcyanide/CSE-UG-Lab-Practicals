#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#define MAX 100

int main(void){
    int fd[2], readChar;
    pid_t childPid;
    char message[] = "A message transferred using pipes";
    char pid[100];
    char readbuffer[MAX] = {' '};

    pipe(fd);

    switch(childPid = fork()){
        case -1:
            perror("fork error");
            exit(1);
            break;

        case 0:
            /* Child process closes the read end of the pipe */
            close(fd[0]);
            /* Send message through the write end of the pipe */
            sprintf(pid, " PID: (%d) ", getpid());
            write(fd[1], strcat(message, pid), (strlen(message) + 1));
            exit(0);
            break;

        default:
            /* Parent process closes the write end of the pipe */
            close(fd[1]);

            /* Read from the pipe */
            readChar = read(fd[0], readbuffer, sizeof(readbuffer));
            printf("\nReceived (%d) message from child: \n\t%s\n\n", getpid(),  readbuffer);
    }

    return 0;
}
