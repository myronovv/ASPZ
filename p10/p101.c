#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int n = 5;

    for (int i = 0; i < n; i++) {

        pid_t pid = fork();

        if (pid < 0) {

            perror("fork failed");
            exit(EXIT_FAILURE);

        } else if (pid == 0) {

            printf("дочірній процес %d (PID : %d , батьківський PID : %d)\n", i + 1, getpid(), getppid());
            sleep(1);
            exit(0);

        } else {
        
            int status;
            waitpid(pid, &status, 0);
            printf("батьківський процес : дочірній процес %d завершився \n", i + 1);
        }

    }

    printf("усі дочірні процеси завершено \n");

    return 0;



}
