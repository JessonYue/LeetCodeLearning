//
// Created by Jesson on 2020/7/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE 1024
/**
 * 测试基本的pipe用法
 * @return
 */
int main(void)
    {
        int n;
        int fd[2];
        pid_t pid;
        char line[MAX_LINE];

        if(pipe(fd)<0){                 /* 先建立管道得到一对文件描述符 */
            exit(0);
        }

        if((pid = fork())<0)            /* 父进程把文件描述符复制给子进程 */
        exit(1);
        else if(pid > 0){                /* 父进程写 */
            close(fd[0]);             /* 关闭读描述符 */
            char data[] = "Hello World!!";
            write(fd[1], data, sizeof(data));
        }
        else{                            /* 子进程读 */
            close(fd[1]);                /* 关闭写端 */
            n = read(fd[0], line, MAX_LINE);
            printf("%s",line);
            fflush(stdout);
        }
      //  while (1){}
      sleep(10);
}