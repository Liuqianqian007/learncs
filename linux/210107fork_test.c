/*************************************************************************
	> File Name: fork_test.c
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 07 Jan 2021 07:36:54 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    for (int i = 1; i <= 3 ; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
        }
        if (pid == 0) {
            printf("I am child process - %d\n", i);
            //break;
        }
        else {
            printf("I am parent process!\n");
        }

    }
    return 0;
}
