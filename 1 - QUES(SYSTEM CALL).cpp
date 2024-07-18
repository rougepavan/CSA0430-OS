#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid, ppid;

    /* Create a new process */
    pid = fork();

    if (pid == 0) {
        /* Child process */
        pid = getpid();
        ppid = getppid();
        printf("Child process: PID = %d, PPID = %d\n", pid, ppid);
    } else {
        /* Parent process */
        pid = getpid();
        ppid = getppid();
        printf("Parent process: PID = %d, PPID = %d\n", pid, ppid);
    }

    return 0;
}
