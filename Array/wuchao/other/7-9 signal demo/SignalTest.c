//
// Created by 吴超 on 2020/7/9.
//
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

unsigned int snooze(unsigned int secs) {
    unsigned int rc = sleep(secs);
    printf("Slept for %d of %d secs.\n", secs - rc, secs);
    return rc;
}

void handler(int sig) {
    printf("catch a signal:%d\n", sig);
}

void signalKill() {
    pid_t pid;
    if ((pid = fork()) == 0) {
        printf("continue...");
        exit(0);
    }
    sleep(1);
    kill(pid, SIGKILL);
    exit(0);
}

void signalAlarm(){
    signal(SIGALRM, handler);
    alarm(5);
    sleep(10);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <secs>\n", argv[0]);
        exit(0);
    }
    if (signal(SIGINT, handler) == SIG_ERR) {
        int errnum = errno;
        fprintf(stderr, "%s (%d: %s)\n", "signal error", errnum, strerror(errnum));
        exit(0);
    }
    snooze(atoi(argv[1]));
    printf("continue...\n");
    exit(0);
//    signalKill();
//    signalAlarm();
}
