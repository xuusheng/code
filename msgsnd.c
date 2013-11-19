#include<stdio.h>
#include<sys/msg.h>
#define MSQ_GET_FLAG 0660
struct msg
{
     long msg_type;
     char text[100];
};


int main(void)
{
     int msqid = msgget(2070101, MSQ_GET_FLAG|IPC_CREAT);
     struct msg msg0;
     msg0.msg_type=1001;
     memcpy(msg0.text, "abc", 3);
     
     
     msgsnd(msqid, &msg0, sizeof(msg0), IPC_NOWAIT);
     

     return 0;
}
