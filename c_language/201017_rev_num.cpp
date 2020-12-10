/*************************************************************************
	> File Name: rev_num.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 17 Oct 2020 07:44:51 PM CST
 ************************************************************************/

#include<stdio.h>

//判断是否为回文数
bool rev_num(int n, int base) {
    if (n < 0) return false;
    //if (__builtin_expect(!!(n < 0), 0))  return false;
    int copy = n;
    int res = 0;
    while(copy) {
        res = res * base + copy % base;
        copy /= base;
    }
    return res == n;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%s\n", rev_num(n, 10) ? "YES" : "NO");
    return 0;
}
