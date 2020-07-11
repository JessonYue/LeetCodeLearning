#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

//
// Created by 吴超 on 2020/7/10.
//
volatile int count = 0;
sem_t* sem;
void* thread(void * t){
    for(int i = 0;i<10000;i++){
        sem_wait(sem);
        count++;
        sem_post(sem);
    }
    return NULL;
}

int main(int argc, char **argv){
    pthread_t t1,t2,t3;
    //mac 不支持sem_init 需要用sem_open 创建信号量。一开始用semTest这个名字，但发现count数量经常不对，改了名字就好了，不知道为什么。
    if((sem = sem_open("sem21233",O_CREAT, S_IWUSR, 1))==SEM_FAILED){
        printf("sem open failed");
    }

    pthread_create(&t1,NULL,thread,NULL);
    pthread_create(&t2,NULL,thread,NULL);
    pthread_create(&t3,NULL,thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    printf("count:%d",count);
    exit(0);
}



