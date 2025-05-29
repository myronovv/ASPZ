#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig, siginfo_t *si, void *context) {
    printf("Отримано сигнал %d з повідомленням: %d\n", sig, si->si_value.sival_int);
}

int main() {
    struct sigaction sa;

    printf("Receiver PID: %d\n", getpid());

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGRTMIN, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) {
        pause();
    }

    return 0;
}
