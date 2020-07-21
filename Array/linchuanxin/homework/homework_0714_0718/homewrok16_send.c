//
// Created by LCX on 2020/7/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX_TEXT 512
struct my_msg_st
{
    long int my_msg_type;
    char some_text[MAX_TEXT];
};

int main()
{
    int running = 1;
    struct my_msg_st some_data;
    int msgid;
    char buffer[BUFSIZ];


    msgid = msgget((key_t)0100, 666|IPC_CREAT); //用一个整数作为一个键值
    if(msgid==-1)
    {
        fprintf(stderr,"msgget failed with errno: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    while(running)
    {
        printf("Enter some text: ");
        fgets(buffer, BUFSIZ, stdin);
        some_data.my_msg_type = 1;
        strcpy(some_data.some_text, buffer);
        if(msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0)==-1)
        {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
        if(strncmp(buffer, "end", 3) == 0)
        {
            running = 0;
        }
    }
    exit(EXIT_SUCCESS);
}