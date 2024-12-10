#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("This is the child process. PID: %d PPID: %d\n", getpid(), getppid());
    } else {
        printf("This is the parent process. PID: %d Child PID: %d\n", getpid(), pid);
    }
    return 0;
}
