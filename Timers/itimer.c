#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <errno.h>

void alarm_handler(int signo) {
    printf("Timer Hit!\n");
}

void foo(void) {

    struct itimerval delay, returned;
    int ret;

    signal(SIGALRM, alarm_handler);

    //current
    delay.it_value.tv_sec = 5;
    delay.it_value.tv_usec = 0;
    //interval
    /*
        If interval is 0, timer is not an interval timer and disarms after
        it_value
    */
    delay.it_interval.tv_sec = 1;
    delay.it_interval.tv_usec = 0;

    ret = setitimer(ITIMER_REAL, &delay, NULL);

    if(ret) {
        perror("setitimer\n");
        return;
    }

    sleep(2);   //sleep for 2 sec

    ret = getitimer(ITIMER_REAL, &returned);
    if(ret) {
        perror("getitimer\n");
        return;
    }

    printf("Current values of ITIMER_REAL-- %ldsec %ldmsec\n", returned.it_value.tv_sec, returned.it_value.tv_usec);

    pause();
    
}

int main(void) {
    foo();
    return 0;
}