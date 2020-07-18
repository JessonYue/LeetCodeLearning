//
// Created by LCX on 2020/7/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct my_msg_st
{
    long int my_msg_type;
    char some_text[BUFSIZ];
};
int main()
{
    int running = 1;
    int msgid;
    struct my_msg_st some_data;
    long int msg_to_receive = 0;  //如果为0，表示消息队列中的所有消息都会被读取

    //创建消息队列：
    msgid = msgget((key_t)0100,666|IPC_CREAT);
    /*IPC(包括消息队列，共享内存，信号量)的xxxget()创建操作时，可以指定IPC_CREAT和IPC_EXCL选项。

以共享内存为例：

当只有IPC_CREAT选项打开时,不管是否已存在该块共享内存，则都返回该共享内存的ID，若不存在则创建共享内存

当只有IPC_EXCL选项打开时，不管有没有该快共享内存，shmget()都返回-1

所以当IPC_CREAT | IPC_EXCL时, 如果没有该块共享内存，则创建，并返回共享内存ID。
                            若已有该块共享内存，则返回-1；*/
    if(msgid == -1)
    {
        fprintf(stderr,"msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    //接收消息队列中的消息直到遇到一个end消息。最后，消息队列被删除。
    while(running)
    {
        //第5个参数为0表示阻塞方式，当消息队列为空，一直等待
        if(msgrcv(msgid, (void *)&some_data, BUFSIZ, msg_to_receive, 0) == -1)
        {
            fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
            exit(EXIT_FAILURE);
        }

        printf("Accept message: %s", some_data.some_text);
        if(strncmp(some_data.some_text, "end", 3)==0)
        {
            running = 0;
        }
    }
    if(msgctl(msgid, IPC_RMID, 0)==-1) // 删除消息队列
    {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}