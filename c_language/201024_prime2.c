/*************************************************************************
	> File Name: 201024_prime2.c
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 25 Oct 2020 06:14:05 PM CST
 ************************************************************************/

#include<stdio.h>

//线性筛——求第10001个素数
//P = M * N，M是合数，N是小于M的最小质因子的质数

//第n个质数的大小不会超过20 * n
#define max_n 200000

int prime[max_n + 5];

void init() {
    for (int i = 2; i <= max_n; i++) {
        //在原数组的前面记录质数，覆盖一部分已经遍历的数
        //没有被标记为1则为质数
        if (!prime[i]) prime[++prime[0]] = i;
        //j遍历已确定的质数
        for (int j = 1; j <= prime[0]; j++) {
            //超过上限
            if ( i * prime[j] > max_n ) break;
            //标记合数P = N * M 
            prime[prime[j] * i] = 1;
            //M中的最小质因子等于N了，跳出循环
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
