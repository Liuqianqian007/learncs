/*************************************************************************
	> File Name: 20201020_gcd.c
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 20 Oct 2020 08:07:45 PM CST
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b) {
    //if (!b) return a;
    //return gcd(b, a % b);
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b)) {
        printf("gcd(%d,%d) = %d\n", a, b, gcd(a, b));
    }
    return 0;
}
