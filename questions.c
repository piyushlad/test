#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int pid = fork();

    if (pid == 0) {
        // child process
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
    } else {
        // parent process
        wait(NULL); // wait for child to finish
        printf("\nChild has finished printing the array.\n");
    }

    return 0;
}