#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

static int sigint_count = 0;
static int sigcount = 0;

void child_over(int SIG){
        if(SIG==SIGCHLD) {
                sigcount++;
                printf("\n Child has departed(SIGCHLD)");
        }
}

void term_if_you_can(int SIG){
        if(SIG==SIGTERM) {
                sigcount++;
                printf("\n Attempt to terminate the program");
        }
}

void stopped(int SIG){
        if(SIG==SIGTSTP) {
                sigcount++;
                printf("\n Can't stop. ");
        }
}

void interrupt(int SIG){
        if(SIG==SIGINT) {
                sigcount++;
                sigint_count+=1;
                printf("\n Can't interrupt.");
        }
}

void abortion(int SIG){
        if(SIG==SIGABRT) {
                sigcount++;
                printf("\n Program has aborted");
        }
}

int main(){
        int pid;

        signal(SIGCHLD,child_over);
        signal(SIGTERM,term_if_you_can);
        signal(SIGTSTP,stopped);
        signal(SIGABRT,abortion);
        signal(SIGINT,interrupt);

        pid=fork();

        if (pid==0)
        {
                printf("\n Child process (%d): \n",getpid());
                sleep(3);
                raise(SIGABRT);
        }

        else if (pid>0)
        {
                int x=pause();
                printf("\n Slept for a total of %d sec \n",x);
                printf("\n\n Encountered a total of %d signals \n\n",sigcount);
        }

        else    printf("\n Couldn't create a new process.");

    return 0;
}
