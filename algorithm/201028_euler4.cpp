/*************************************************************************
	> File Name: euler_4.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 28 Oct 2020 06:42:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//最大回文乘积-palindromic number

int func(int x) {
    int t = 0, raw = x;
    while (x) {
        t = t * 10 + x % 10;
        x /= 10;
    }
    return t == raw;
}

int main() {
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int t = i * j;
            if (func(t)) {
                ans = max(ans,t);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
