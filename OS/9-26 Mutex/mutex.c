#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<pthread.h>

int global_sum=0;

/*  A program to print the sum of a numbers given using command line arguments
    using separate threads and display the final result. Use mutex locks to guarantee synchronisation.
*/

typedef struct thread_info{
    pthread_t thread_id;
    int thread_no;
    void *argument;
}thread;

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void* thread_sum(void *x){

    printf("\n Thread with arg %d awaiting lock\n",*(int *)x);
    pthread_mutex_lock(&mutex);

    printf(" Thread with arg %d holding lock\n",*(int *)x);
    global_sum=0;
    int y = *(int *)x;
    for(int i=1; i<=y; i++){

        global_sum+=i;
    }

    printf(" Thread with arg %d releasing lock\n",*(int *)x);
    *(int *) x = global_sum;

    pthread_mutex_unlock(&mutex);
    pthread_exit(x);
}

void print_error(char *message){
    fprintf(stderr, "%s\n",message);
    exit(EXIT_FAILURE);
}

int main(int argc,char **argv)
{
    int s;
    if(argc<2)
        print_error(" Usage: count <number> <number>\n");

    pthread_attr_t attr;                                            //Set of attribites for our own thread structure
    s=pthread_attr_init(&attr);                                     //initialise the attributes for the thread stack
        assert(s==0);

    thread *tid=(thread *)calloc(argc-1,sizeof(thread));                        //Allocate memory for threads
    if(tid==NULL)
        print_error(" Couldn't Allocate Memory");

    int arg_threads[argc - 1];

    for(int i=0; i<argc-1; i++){

        arg_threads[i] = atoi(argv[i+1]);
        tid[i].argument = &arg_threads[i];                                                   //Set the argument as the input
        tid[i].thread_no=i+1;

        printf("\n Creating Thread %d with arg: %d\n",tid[i].thread_no,arg_threads[i]);
        s=pthread_create(&tid[i].thread_id,&attr,thread_sum,tid[i].argument);   //Create the thread in background
        assert (s==0);
    }

    s=pthread_attr_destroy(&attr);              //We don't need the attributes now as the threads are up and running.
    assert(s==0);

    void * status ;                     //To get the value from the thread

    for(int i=0; i<argc-1; i++){
        s=pthread_join(tid[i].thread_id,&status);                          //make calling thread wait for the called thread

        printf("\n Thread %d finished. Returned %d \n\n",tid[i].thread_no ,*(int *)status);
    }

    return 0;
}
