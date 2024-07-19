#include <stdio.h>
#include <sys/msg.h>

#define MSG_QUEUE_KEY 1234

int main() {
    // Create a message queue
    int msqid = msgget(MSG_QUEUE_KEY, IPC_CREAT | 0666);

    // Fork a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process sends a message
        struct msgbuf {
            long mtype;
            char mtext[100];
        } msg;
        msg.mtype = 1;
        strcpy(msg.mtext, "Hello from child!");
        msgsnd(msqid, &msg, sizeof(msg.mtext), 0);
    } else {
        // Parent process receives the message
        struct msgbuf msg;
        msgrcv(msqid, &msg, sizeof(msg.mtext), 1, 0);
        printf("%s\n", msg.mtext);
    }

    // Clean up
    msgctl(msqid, IPC_RMID, NULL);

    return 0;
}
