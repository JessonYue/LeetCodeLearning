//
// Created by Jesson on 2020/7/23.
//

#include<sys/types.h>

#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 512

struct message{
    long msg_type;
    char msg_text[BUFFER_SIZE];
};

int main(){
    int qid;
    key_t key;
    struct message msg;
    //ftok根据不同路径和关键字产生标准的KEY
    if((key = ftok(".", 'a')) == -1){
        perror("ftok");
        exit(1);
    }
    //create messagequeue
    if((qid = msgget(key, IPC_CREAT|0666)) == -1){
        perror("msgget");
        exit(1);
    }
    printf("open queue %d\n", qid);
    while(1){
        printf("enter some message to the queue:");
        if((fgets(msg.msg_text, BUFFER_SIZE, stdin)) == NULL){
            puts("no message");
            exit(1);
        }
        msg.msg_type = getpid();//消息类型为进程号
        if((msgsnd(qid, &msg, strlen(msg.msg_text), 0)) < 0)//发送消息
            {
            perror("message posted");
            exit(1);
            }
        if(strncmp(msg.msg_text, "quit", 4) == 0)
        {
            break;
        }
    }
    exit(0);
}