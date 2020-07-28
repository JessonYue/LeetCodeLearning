//
// Created by Jesson on 2020/7/20.
//

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

static sem_t g_semaphore;
static const int g_iRunTime = 5000;

void* Fun(void* ptr)
{
    int iRunTime = 0;
    while(++iRunTime< g_iRunTime)
    {
        sem_wait(&g_semaphore);
        cout<< "Fun() is running!"<< iRunTime << endl;
        sem_post(&g_semaphore);
        usleep(100);
    }
}

int main()
{
    pthread_t hHandle;
    pthread_t hHandle2;
    sem_init(&g_semaphore, 0, 1);
    int iRet = pthread_create(&hHandle, NULL, Fun, NULL);
    if(0 != iRet)
    {
        cout << "Create thread failed!" << endl;
    }
    sleep(1);
    int iRunTime = 0;
    while(++iRunTime<g_iRunTime)
    {
        sem_wait(&g_semaphore);
        cout << "main is running!" << endl;
        sem_post(&g_semaphore);
        usleep(100);
    }
    pthread_join(hHandle, NULL);
    return 0;
}