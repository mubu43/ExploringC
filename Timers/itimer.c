#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <errno.h>

void alarm_handler(int signo) {
    printf("Timer Hit!\n");
}

void foo(void) {

    struct itimerval delay;
    int ret;

    signal(SIGALRM, alarm_handler);

    //current
    delay.it_value.tv_sec = 3;
    delay.it_value.tv_usec = 0;
    //interval
    delay.it_interval.tv_sec = 1;
    delay.it_interval.tv_usec = 0;

    ret = setitimer(ITIMER_REAL, &delay, NULL);

    if(ret) {
        perror("setitimer\n");
        return;
    }

    pause();
    
}

int main(void) {
    foo();
    return 0;
}