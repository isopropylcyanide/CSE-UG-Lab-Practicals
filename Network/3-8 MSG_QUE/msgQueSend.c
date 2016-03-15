#include <stdio.h>
#include <string.h>
#include <sys/msg.h>

#define MSG_QUE_KEY 31
#define MAX_MSG_LEN 100
#define MSG_FLAG  IPC_CREAT | 0666
// A program to demo the working of message queues in IPC (sender)

typedef struct msgbuf{
    long mtype;
    char mtext[MAX_MSG_LEN];
}newMessage;


int main(){

    newMessage sendMsg;
    int msgQue;

    printf("\nEnter a message to send: ");
    scanf("%[^\n]",sendMsg.mtext);

    // Create a new message queue exclusively for the process
    if ((msgQue = msgget(MSG_QUE_KEY, MSG_FLAG)) < 0){
        perror("Message Queue Error");
        return -1;
    }

    printf("\nIn Parent Sending : %s => %ld\n", sendMsg.mtext, strlen(sendMsg.mtext) +1 );

    if (msgsnd(msgQue, &sendMsg, strlen(sendMsg.mtext) +1, IPC_NOWAIT) < 0)
        perror("\nParent message queue error");

    else
        printf("\nParent Message Sent\n");

    return 0;
}
