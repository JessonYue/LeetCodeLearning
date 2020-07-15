#include <stdio.h>
#include <malloc.h>
#include <semaphore.h>
#include <Signal.h>
#include <stdlib.h> // exit(), EXIT_SUCCESS
#include <pthread.h> // pthread_create(), pthread_join()
sem_t binSem;
volatile int cout=0;
void* thread(void* arg);
int main() {
    int res=0;
    int *thread_ret = NULL;

    int arg = 10;
    int arg2 = 11;
    int arg1 = 12;
    res=sem_init(&binSem,0,10);
    if (res) {
        printf("Semaphore initialization failed!!/n");
        exit(EXIT_FAILURE);
    }
    pthread_t th1,th2,th3;
    res= pthread_create(&th1, NULL, thread, &arg);
    res= pthread_create(&th2, NULL, thread, &arg1);
    res= pthread_create(&th3, NULL, thread, &arg2);
    if (res) {
        printf("Thread creation failed!!/n");
        exit(EXIT_FAILURE);
    }
    sem_post(&binSem);
    pthread_join(th2,NULL);
    pthread_join(th1,NULL);
    pthread_join(th3,NULL);
    printf( "thread_ret = %d.\n", cout );
    return 0;
}

void* thread(void* arg) {
    for (int i = 0; i < 10000; ++i) {
        sem_wait(&binSem);
        printf("Thread： %d \n",*(int* )arg);
        cout++;
        sem_post(&binSem);
    }
    return NULL;
}
