#include <stdio.h>
#include <unistd.h>


void wait_sem(int *s){
    while( *s <= 0);
    *s -= 1;
}

void signal_sem(int *s){
    *s += 1;
}


int main(){
    int sem = 1;
    
    int pid = fork();
    if (pid < 0){
        printf("Error\n");
        return 1;
    }

    int self = getpid();
    if (pid == 0){
        printf("PID %d is waiting\n", self);
        wait_sem(&sem);
        printf("PID %d is done waiting\n", self);
    }else{
        printf("PID %d is signaling\n", self);
        signal_sem(&sem);
        printf("PID %d is done signaling\n", self);
    }

    return 0;
}
