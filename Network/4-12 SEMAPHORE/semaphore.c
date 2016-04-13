#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void printError(char *msg){
    perror(msg);
    exit(-1);
}

// A semaphore program to make sure that child thread executes first and then the
// section after the thread creation in main is executed

sem_t sem;

void * childThreadFunc(void * arg){
    printf("\n In child thread function\n");

    // release the lock
    sem_post(&sem);
    return NULL;
}

int main(){

    // Create a binary semaphore
    sem_init(&sem, 0, 0);

    printf("\n In parent: Start\n");

    // Create a child thread
    pthread_t thread;
    pthread_create(&thread, NULL, childThreadFunc, NULL);

    // Wait for the child here
    sem_wait(&sem);
    printf("\n In parent: End\n");

    return 0;
}
