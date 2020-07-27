//
// Created by Jesson on 2020/7/20.
//

#include<signal.h>
#include<stdio.h>
#include <unistd.h>

void handler(int signum)
{
    if(signum == SIGIO)
        printf("SIGIO   signal: %d\n", signum);
    else if(signum == SIGUSR1)
        printf("SIGUSR1   signal: %d\n", signum);
    else
        printf("error\n");
}

int main(void)
{
    signal(SIGIO, handler);
    signal(SIGUSR1, handler);
    printf("%d  %d\n", SIGIO, SIGUSR1);
    for(;;)
    {
        sleep(10000);
    }
    //return 0;
}