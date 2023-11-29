
// Program to implement IPC between two processes using two Pipes

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int fd_1[2];
    int fd_2[2];
    char buffer[20];
    pid_t pid;
    int processId;
    pipe(fd_1);
    pipe(fd_2);
    pid = fork();
    if(pid == 0) {
        processId = getpid();
        close(fd_1[0]);
        printf("\nI am Child Process (PID: %d) and writing message to the parent\n", processId);
        write(fd_1[1], "HELLO\n", 5);
        close(fd_1[1]);
        sleep(2);
        close(fd_2[1]);
        printf("\nI am Child Process (PID: %d) and reading message from the parent\n", processId);
        printf("Message is: \n");
        read(fd_2[0], buffer, 5);
        write(STDOUT_FILENO, buffer, 5);
    }
    else if(pid > 0) {
        sleep(1);
        processId = getpid();
        close(fd_1[1]);
        printf("\nI am Parent Process (PID: %d) and reading message from the Child\n", processId);
        printf("Message is: \n");
        read(fd_1[0], buffer, 5);
        close(fd_1[1]);
        write(STDOUT_FILENO, buffer, 5);
        close(fd_2[0]);
        printf("\nI am Parent Process (PID: %d) and writing message to the Child\n", processId);
        write(fd_2[1], "HELLO\n", 5);
        close(fd_2[0]);
    }

    return 0;
}
