/*************************************************************************
	> File Name: 201029_ip.c
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 29 Oct 2020 07:20:31 PM CST
 ************************************************************************/

#include<stdio.h>

//实现IP地址转整数功能

union IP {
    struct {
        unsigned char a;
        unsigned char b;
        unsigned char c;
        unsigned char d;
    } ip;
    unsigned int num;
};
//判断电脑是否为小端机
int is_little() {
    int num = 1;
    return ((char *)(&num))[0];
}

int main() {
    printf("%d\n", is_little());
    union IP p;
    char str[100] = {0};
    int arr[4];
    while (~scanf("%s", str)) {
        sscanf(str, "%d.%d.%d.%d", arr, arr + 1, arr + 2, arr + 3);
        p.ip.d = arr[0];//小端机，整数存储倒过来
        p.ip.c = arr[1];
        p.ip.b = arr[2];
        p.ip.a = arr[3];
        printf("%u\n", p.num);
    }
    return 0;
}
