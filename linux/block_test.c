/*************************************************************************
	> File Name: block_test.c
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 05 Jan 2021 06:53:54 PM CST
 ************************************************************************/
#include "head.h"

int main() {
    int age;
    make_nonblock(0);
    sleep(5);
    int ret = scanf("%d", &age);
    printf("liuq is %d years old! <%d>\n", age, ret);
    perror("scanf");
    return 0;
}

