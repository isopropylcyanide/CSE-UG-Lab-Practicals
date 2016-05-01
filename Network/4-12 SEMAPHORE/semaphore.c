#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>

#define SEMFLAG IPC_CREAT | 0666
#define NUMSEMS 1

void error(char *msg){
  perror(msg);
  exit(1);
}

int main(){
    int j;
    pid_t pid;
    int semid; /* semid of semaphore set */
    key_t key ; /* key to pass to semget() */
    int nsops; /* number of operations to do */

    struct sembuf *sops = (struct sembuf *) malloc(2 * sizeof(struct sembuf));
    /* ptr to operations to perform */

    //generate key
    if ((key = ftok("semaphore.c", 'Q')) == -1)
       error("ftok");

    /* set up semaphore */

    // printf("\nsemget: Setting up semaphore: semget(%#lx, %\%#o)\n",key, nsems, semflg);
    if ((semid = semget(key, NUMSEMS, SEMFLAG)) == -1)
        error("semget: semget failed");


    if ((pid = fork()) < 0)
        error("fork");

    if (pid == 0){ //child
        nsops = 2;

        /* wait for semaphore to reach zero */
        sops[0].sem_num = 0;
        sops[0].sem_op = 0; /* wait for semaphore flag to become zero */
        sops[0].sem_flg = SEM_UNDO; /* take off semaphore asynchronous  */

        sops[1].sem_num = 0;
        sops[1].sem_op = 1; /* increment semaphore*/
        sops[1].sem_flg = SEM_UNDO | IPC_NOWAIT; /* take off semaphore */

        printf("\nsemop:Child  Calling semop(%d, &sops, %d) with:", semid, nsops);
        for (j = 0; j < nsops; j++){
             printf("\n\tsops[%d].sem_num = %d, ", j, sops[j].sem_num);
             printf("sem_op = %d, ", sops[j].sem_op);
             printf("sem_flg = %#o\n", sops[j].sem_flg);
        }

        /* Make the semop() call and report the results. */
        if ((j = semop(semid, sops, nsops)) == -1){
            perror("semop: semop failed");
        }
        else{
            printf("\n\nChild process now in control\n");
            nsops = 1;

            /* wait for semaphore to reach zero */
            sops[0].sem_num = 0;
            sops[0].sem_op = -1; /* Give UP COntrol of track */
            sops[0].sem_flg = SEM_UNDO | IPC_NOWAIT; /* take off semaphore, asynchronous  */

            if ((j = semop(semid, sops, nsops)) == -1)
                perror("semop: semop failed");
            else
                printf("\nChild process giving up control\n\n");
            sleep(1); /* halt process to allow parent to catch semaphore change first */
        }

    }
    else{ /* parent */
        nsops = 2;
        /* wait for semaphore to reach zero */
        sops[0].sem_num = 0;
        sops[0].sem_op = 0; /* wait for semaphore flag to become zero */
        sops[0].sem_flg = SEM_UNDO; /* take off semaphore asynchronous  */

        sops[1].sem_num = 0;
        sops[1].sem_op = 1; /* increment semaphore */
        sops[1].sem_flg = SEM_UNDO | IPC_NOWAIT; /* take off semaphore */

        printf("\nsemop:Parent Calling semop(%d, &sops, %d) with:", semid, nsops);
        for (j = 0; j < nsops; j++){
            printf("\n\tsops[%d].sem_num = %d, ", j, sops[j].sem_num);
            printf("sem_op = %d, ", sops[j].sem_op);
            printf("sem_flg = %#o\n", sops[j].sem_flg);
        }

        /* Make the semop() call and report the results. */
        if ((j = semop(semid, sops, nsops)) == -1)
            perror("semop: semop failed");
        else{
            printf("\nParent process now in control\n");
            nsops = 1;

            /* wait for semaphore to reach zero */
            sops[0].sem_num = 0;
            sops[0].sem_op = -1; /* Give UP Control of track */
            sops[0].sem_flg = SEM_UNDO | IPC_NOWAIT; /* take off semaphore, asynchronous  */

            if ((j = semop(semid, sops, nsops)) == -1)
                perror("semop: semop failed");
            else
                printf("\nParent process now releasing control\n\n");
            sleep(1); /* halt process to allow child to catch semaphore change first */
        }
    }
    return 0;
}
