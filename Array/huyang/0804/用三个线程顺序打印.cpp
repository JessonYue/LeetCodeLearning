#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include "../../../../../Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h"

using namespace std;
pthread_mutex_t g_mutex1;
pthread_cond_t g_cond1;
pthread_mutex_t g_mutex2;
pthread_cond_t g_cond2;
pthread_mutex_t g_mutex3;
pthread_cond_t g_cond3;

static int num = 0;

void *thread1(void *id);

void *thread2(void *id);

void *thread3(void *id);

int main(int argc, char *argv[]) {
    pthread_mutex_init(&g_mutex1, NULL);
    pthread_cond_init(&g_cond1, NULL);
    pthread_mutex_init(&g_mutex1, NULL);
    pthread_cond_init(&g_cond1, NULL);
    pthread_mutex_init(&g_mutex1, NULL);
    pthread_cond_init(&g_cond1, NULL);

    pthread_t id[3];

    int n1 = 0;
    int n2 = 1;
    int n3 = 2;
    pthread_create(&id[0], NULL, thread1, &n1);
    pthread_create(&id[1], NULL, thread1, &n2);
    pthread_create(&id[2], NULL, thread1, &n3);

    pthread_join(id[0], NULL);
    pthread_join(id[1], NULL);
    pthread_join(id[2], NULL);

    pthread_cond_destroy(&g_cond1);
    pthread_mutex_destroy(&g_mutex1);
    pthread_cond_destroy(&g_cond1);
    pthread_mutex_destroy(&g_mutex1);
    pthread_cond_destroy(&g_cond1);
    pthread_mutex_destroy(&g_mutex1);

    int c;
    while ((c = getchar()) != 'c') {
        sleep(1);
    }

    cout << "exit process from main func" << endl;
    return 0;

}

void *thread1(void *id) {
    while (1) {
        pthread_mutex_lock(&g_mutex1);
        int d = *(int *)id;
        if (num % 3 != d) {
            //enter wait will unlock resource and block current thread.
            //broadcast will active wait func
            pthread_cond_wait(&g_cond1, &g_mutex1);
            //end wait will lock resource
        }else{
            printf("thread %d, %c \n",d, ('A'+num));
            ++num;
//            pthread_cond_broadcast(&g_cond1);
//            pthread_mutex_unlock(&g_mutex1);

        }


        if (num > 25) {
            pthread_cond_broadcast(&g_cond1);
            pthread_mutex_unlock(&g_mutex1);
            pthread_exit(0);
        }
        pthread_cond_broadcast(&g_cond1);
        pthread_mutex_unlock(&g_mutex1);
    }
}


void *thread2(void *id) {
    while (1) {
        pthread_mutex_lock(&g_mutex2);

        if (num % 2 == 0) {
            pthread_cond_wait(&g_cond2, &g_mutex2);
        }

        if (num > 10000) {
            pthread_mutex_unlock(&g_mutex2);
            pthread_exit(0);
        }

        cout << "thread 2 : " << num << endl;
        ++num;
        pthread_cond_broadcast(&g_cond2);
        pthread_mutex_unlock(&g_mutex2);
    }
}

void *thread3(void *id) {
    while (1) {
        pthread_mutex_lock(&g_mutex3);

        if (num % 2 == 0) {
            pthread_cond_wait(&g_cond3, &g_mutex3);
        }

        if (num > 10000) {
            pthread_mutex_unlock(&g_mutex3);
            pthread_exit(0);
        }

        cout << "thread 3 : " << num << endl;
        ++num;
        pthread_cond_broadcast(&g_cond3);
        pthread_mutex_unlock(&g_mutex3);
    }
}
