#include<stdio.h>
#include<sys/msg.h>
#define MSQ_GET_FLAG 0660
struct mymsg
{
     long msg_type;
     char text[100];
};


int main(void)
{
     int msqid = msgget(2070101, MSQ_GET_FLAG|IPC_CREAT);
     struct mymsg msg0;
     
     msgrcv(msqid, &msg0, 6, 0, IPC_NOWAIT);
     
     return 0;
}
