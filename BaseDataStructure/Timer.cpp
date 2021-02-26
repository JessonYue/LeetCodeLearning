//
// Created by Jesson on 2020/8/5.
//

#include <unistd.h>
#include "Timer.h"
float time_use = 0;
void signalHandler(int signo) {
    struct timeval start,end;
    switch (signo) {
        case SIGALRM:
            gettimeofday(&start,NULL);
            printf("Caught the SIGALRM signal!\n");
            gettimeofday(&end,NULL);
            time_use += (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);//微秒

            if(time_use > 3000000){
                printf("time_use is %fn",time_use);
                time_use = 0;
            }
            break;
    }
}


int main(int argc, char *argv[]) {
//    signal(SIGALRM, signalHandler);
//
//    struct itimerval new_value, old_value;
//    new_value.it_value.tv_sec = 1;//延时1s
//    new_value.it_value.tv_usec = 0;
//    new_value.it_interval.tv_sec = 0;
//    new_value.it_interval.tv_usec = 200000; //200ms触发一次
//    setitimer(ITIMER_REAL, &new_value, &old_value);
//
//    float time_use=0;
//    struct timeval start,end;
//
//    gettimeofday(&start,NULL);
//    printf("start.tv_sec:%d\n",start.tv_sec);
//    printf("start.tv_usec:%d\n",start.tv_usec);
//
//
//    for (;;);
    {
        float time_use=0;
        struct timeval start;
        struct timeval end;//struct timezone tz;
        gettimeofday(&start,NULL); //gettimeofday(&start,&tz);

        while(1)
        {
            gettimeofday(&end,NULL);

            time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒

            if((int32_t)time_use % 6000000 == 0)
            {
                printf("time is enough!\n");
                //start == 0;
            }

        }
    }
    return 0;
}