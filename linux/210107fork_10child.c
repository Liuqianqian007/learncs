/*************************************************************************
	> File Name: fork_10child.c
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 07 Jan 2021 07:44:01 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    int i;
    for (i = 1; i <= 10; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid == 0) {
            printf("我是第%d个孩子\n", i);
            break;
        }
    }
    sleep(100);
    return 0;
}
