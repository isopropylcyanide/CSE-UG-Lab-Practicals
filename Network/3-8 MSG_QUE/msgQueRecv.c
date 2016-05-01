#include <stdio.h>
#include <sys/msg.h>

#define MSG_QUE_KEY 31
#define MAX_MSG_LEN 100
#define MSG_FLAG  IPC_CREAT | 0666
// A program to demo the working of message queues in IPC (receiver)

typedef struct msgbuf{
    long mtype;
    char mtext[MAX_MSG_LEN];
}newMessage;

int main(){
    newMessage recvMsg;
    struct msqid_ds wholeQueue;

    int msgQue;

    if ((msgQue = msgget(MSG_QUE_KEY, MSG_FLAG))< 0)
        perror("\nMessage Queue doesn't exist\n");

    else{//queue exists
        if (msgrcv(msgQue, &recvMsg, MAX_MSG_LEN, 0, IPC_NOWAIT) < 0)
        perror("\nMessage Reading failed\n\n");

        else {
            printf("\nMessage Received: %s\n", recvMsg.mtext );
            if (msgctl(msgQue, IPC_STAT, &wholeQueue) == 0){
                printf("\nNumber of messages in Queue: %ld", wholeQueue.msg_qnum);
                printf("\nLast PID that wrote: %d", wholeQueue.msg_lspid);
                printf("\nTime of last write: %ld", wholeQueue.msg_stime);
                printf("\nLast PID that read: %d", wholeQueue.msg_lrpid);
                printf("\nTime of last read: %ld\n\n", wholeQueue.msg_rtime);
                msgctl(msgQue, IPC_RMID, NULL); //Remove message
            }
        }

    }
    return 0;
}
