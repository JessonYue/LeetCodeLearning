//
// Created by Jesson on 2020/7/18.
//

#include "semaphore.h"
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <semaphore.h>
#include <cstdio>

typedef int que_t[6];
que_t q;
sem_t p;//可生产的数量
sem_t c;//可消费的数量

//生产者线程
void *p_func(void *arg){
    int t = 0;
    while(1){
        sem_wait(&p);
        q[t] = rand() % 1000 + 1;
        printf("p:%d\n", q[t]);
        t = (t + 1) % 6;
        sem_post(&c);
        sleep(rand()%4+1);
    }
    return NULL;
}

//消费者线程
void *c_func(void *arg){
    int h = 0;
    int tmp;
    while(1){
        sem_wait(&c); //一操作 如果当前信号的值大于0,继续立即返回.
        //如果当前信号量的值等于0.阻塞,直到信号量的值变为大于0.
        tmp = q[h];
        q[h] = -1;
        h = (h+1)%6;
        sem_post(&p);
        printf("c:%d\n", tmp);
        sleep(rand()%4+1);
    }
    return 0;
}

int main(void){
    //初始化信号量的值
    sem_init(&p, 0, 6); //初始化一个匿名信号量
    sem_init(&c, 0, 0);
    srand(time(NULL));
    //创建两个线程，一个用于生产者，一个用于消费者
    pthread_t tid, cid;
    pthread_create(&tid, NULL, p_func, NULL);
    pthread_create(&cid, NULL, c_func, NULL);
    //阻塞等待线程汇合
    pthread_join(tid, NULL);
    pthread_join(cid, NULL);
    //销毁信号量
    sem_destroy(&p);
    sem_destroy(&c);
    return 0;
}