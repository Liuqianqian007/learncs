/*************************************************************************
	> File Name: 210107exec.c
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 07 Jan 2021 08:11:08 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid == 0) {
        execlp("vim", "vim", "210107exec.c", NULL);
        //exec函数族重新开辟一个镜像，子进程中没有后面的代码
        sleep(1000);
        printf("In End!\n");
    }
    else {
        wait(NULL);
        printf("After Child terminated\n");
        sleep(5);
    }
}
