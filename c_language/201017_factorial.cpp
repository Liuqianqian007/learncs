/*************************************************************************
	> File Name: factorial.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 17 Oct 2020 08:51:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//阶乘
int factorial(int n) {
    if (n == 1)  return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", factorial(n));
}

