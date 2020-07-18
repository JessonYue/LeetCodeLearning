//
// Created by 张俊伟 on 2020/7/8.
//
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define NUM_THREAD 16
typedef struct threadData {
    int *intptr;
    pthread_mutex_t *mlock;
} ThreadData;

void *print_hello(void *arg) {
    printf("print_hello: %d\n", *((int *) arg));
    return NULL;
}

void *thread_func(void *arg) {
    ThreadData *p = (ThreadData *) arg;
//    printf("thread id: %d\n",  pthread_self());

    while (1) {
        pthread_mutex_lock(p->mlock);
        (*p->intptr)++;
        (*p->intptr)--;

        if (*(p->intptr) != 0) {
            printf("thread_func: %d\n", *(p->intptr));
            return NULL;
        }
        pthread_mutex_unlock(p->mlock);
    }
    return NULL;
}


int main2() {
    int arg = 0;
    pthread_mutex_t mlock;
    pthread_mutex_init(&mlock, NULL);

    ThreadData threadData;
    threadData.intptr = &arg;
    threadData.mlock = &mlock;
    pthread_t tid[NUM_THREAD];
    int rtv = 0;
    for (int i = 0; i < NUM_THREAD; ++i) {
        rtv = pthread_create(&tid[i], NULL, thread_func, (void *) &threadData);
        if (rtv != 0) {
            printf("Error: pthread_create return %d\n", rtv);
            return EXIT_FAILURE;
        }
    }
    for (int j = 0; j < NUM_THREAD; ++j) {
        rtv = pthread_join(tid[j], NULL);
        if (rtv != 0) {
            printf("Error: pthread_join return %d\n", rtv);
            return EXIT_FAILURE;
        }
    }
    pthread_mutex_destroy(&mlock);
    printf("main thread over \n");
    return EXIT_SUCCESS;
}

int main1() {
    int arg = 12346;
    pthread_t second;
    int rtv = pthread_create(&second, NULL, print_hello, (void *) &arg);
    if (rtv != 0) {
        printf("Error: pthread_create return %d\n", rtv);
        return EXIT_FAILURE;
    }

    rtv = pthread_join(second, NULL);
    if (rtv != 0) {
        printf("Error: pthread_join return %d\n", rtv);
        return EXIT_FAILURE;
    }
    printf("main thread over \n");

    return EXIT_SUCCESS;
}


 sem_t sem;

void *change_resurce(void *res) {
    char *msg = (char *) res;
    while (1) {
        sem_wait(&sem);
        strcat(msg, "b");
        printf("%s\n", msg);
    }
}

void semaphore_test() {
    char *resource = "";
    int ret = sem_init(&sem, 0, 0);
    if (ret == -1) {
        printf("sem_init failed \n");
        return;
    }

    pthread_t pthread;
    pthread_create(&pthread, NULL, change_resurce, (void *)resource);

    while (1){
        sem_post(&sem);
        sleep(1000);
    }
//   int rtv = pthread_join(pthread, NULL);
//    if (rtv != 0) {
//        printf("Error: pthread_join return %d\n", rtv);
//        return;
//    }

    sem_destroy(&sem);


}

int main() {
    semaphore_test();
    printf("main thread over \n");
    return EXIT_SUCCESS;
}