/*************************************************************************
	> File Name: common.c
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 05 Jan 2021 06:40:04 PM CST
 ************************************************************************/
#include "head.h"

int make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }    
    flag |= O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}

int make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }    
    flag &= ~O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}
