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
    int msgQue;

    if ((msgQue = msgget(MSG_QUE_KEY, MSG_FLAG))< 0)
        perror("\nMessage Queue doesn't exist\n");

    else if (msgrcv(msgQue, &recvMsg, MAX_MSG_LEN, 0, 0) < 0)
        perror("\nMessage Reading failed\n");

    else
        printf("\nMessage Received: %s\n", recvMsg.mtext );
    return 0;
}a
