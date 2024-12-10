#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    int pipefd[2]; 
    pid_t pid;
    char write_msg[] = "Hello from Rushil";
    char read_msg[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { 
        close(pipefd[1]);
        ssize_t bytesRead = read(pipefd[0], read_msg, sizeof(read_msg));
        if (bytesRead == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("Child received: %s\n", read_msg);
        close(pipefd[0]); 
    } else { 
        close(pipefd[0]); 
        ssize_t bytesWritten = write(pipefd[1], write_msg, strlen(write_msg) + 1);
        if (bytesWritten == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        printf("Parent sent: %s\n", write_msg);
        close(pipefd[1]);
    }
    return -1;
}

