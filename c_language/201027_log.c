/*************************************************************************
	> File Name: 201027_log.c
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 27 Oct 2020 07:51:47 PM CST
 ************************************************************************/

#include<stdio.h>

//实现打印LOG的函数，输出所在函数及行号等信息
//变参宏
#define DEBUG
#ifdef DEBUG
#define log(frm, args...){\
    printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__);\
    printf(frm, ##args);\
    printf("\n");\
}
#else
#define log(frm, args...)
#endif


#define contact(a, b) a##b

int main() {
    int a = 123;
    int b = 234;
    int abcdef = 0, abc, def;
    log("%d%d", b, a);
    log("hello world");
    contact(abc, def) = 666;
    log("%d", abcdef);
    return 0;
}
