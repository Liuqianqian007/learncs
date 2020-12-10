/*************************************************************************
	> File Name: euler_14.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 28 Oct 2020 08:22:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//最长的考拉兹序列-longest collatz sequence
//递归时结合记忆数组可提高运行效率
int num[10000000];

//t是数n产生的考拉兹序列的项数
int func(long long n) {
    //递归边界：1产生的考拉兹序列项数是1
    if (n == 1) return 1;
    if (n < 10000000 && num[n]) return num[n];
    int t;
    //递归条件：上一层的项数是下一层的项数加1
    if (n % 2 == 0) {
        t = func(n / 2) + 1;
    }
    else {
        t = func(3 * n + 1) + 1;
    }
    if (n < 10000000) {
        num[n] = t;
    }
    return t;
}

int main() {
    int ans = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (func(ans) < func(i)) {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
