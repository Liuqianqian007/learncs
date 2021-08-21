/*************************************************************************
	> File Name: 210107fork.c
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 07 Jan 2021 06:33:58 PM CST
 ************************************************************************/

#include "head.h"
#include <sys/wait.h>

int main() {
    
    pid_t pid;
    int status;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid == 0) {
        sleep(5);
        printf("In Child!\n");
        //return 1;
    }
    else {
        wait(&status);
        printf("Wait Status = %d\n", status);
    }
    
    /*
    char name[20] = {0};
    scanf("%s", name);
    printf("%s", name);
    fork();
    */
    return 0;
}
