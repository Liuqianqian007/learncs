/*************************************************************************
	> File Name: 201024_prime.c
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 25 Oct 2020 05:10:10 PM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 100
//素数筛实现

int prime[max_n + 5] = {0};//多开5位以防不小心溢出，数组定义在函数外时默认初始化为0值
void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i]) continue;//减少缩进
        prime[++prime[0]] = i;//记录素数，prime[0]为素数个数
        for (int j = i * i; j <= max_n; j += i) {//j 初始化为i * i而不是i * 2，是为了减少重复标记
            prime[j] = 1;
        }
    }
    return;
}

int main() {
    init();
    for (int i = 1; i <= prime[0]; i++) {
        printf("%d\n", prime[i]);
    }
    return 0;
}
