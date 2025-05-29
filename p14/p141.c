#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

void signal_handler(int sig) {
    printf("[SIGNAL %d] Отримав потік: %ld\n", sig, pthread_self());
}

void *thread_func(void *arg) {
    printf("[THREAD] Потік запущено: %ld\n", pthread_self());
    while (1) pause();
    return NULL;
}

void test_alarm() {
    printf("\n=== Тест alarm() ===\n");
    signal(SIGALRM, signal_handler);
    alarm(2); 
    sleep(3);
}

void test_setitimer() {
    printf("\n=== Тест setitimer() ===\n");
    signal(SIGALRM, signal_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);
    sleep(3);
}

void test_timer_create() {
    printf("\n=== Тест timer_create() ===\n");

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = (void *)signal_handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, NULL);

    timer_t timerid;
    struct sigevent sev;
    struct itimerspec its;

    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = &timerid;

    if (timer_create(CLOCK_REALTIME, &sev, &timerid) == -1) {
        perror("timer_create");
        exit(EXIT_FAILURE);
    }

    its.it_value.tv_sec = 2;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;

    timer_settime(timerid, 0, &its, NULL);
    sleep(3);
}

int main() {
    pthread_t tid;

    printf("[MAIN] Головний потік: %ld\n", pthread_self());

    if (pthread_create(&tid, NULL, thread_func, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    sleep(1);

    test_alarm();
    test_setitimer();
    test_timer_create();

    pthread_cancel(tid); 
    pthread_join(tid, NULL);

    return 0;
}
