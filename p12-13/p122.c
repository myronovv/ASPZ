#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Використання: %s <PID> <число>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid = atoi(argv[1]);
    int value = atoi(argv[2]);

    union sigval sv;
    sv.sival_int = value;

    if (sigqueue(pid, SIGRTMIN, sv) == -1) {
        perror("sigqueue");
        exit(EXIT_FAILURE);
    }

    printf("Надіслано %d до PID %d\n", value, pid);

    return 0;
}
