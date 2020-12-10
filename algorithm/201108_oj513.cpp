/*************************************************************************
	> File Name: 201108_oj513.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 08 Nov 2020 07:34:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//暴力枚举
//用函数func从1~x判断是否包含数字t
int func(int x, int t) {
    while(x) {
        if (x % 10 == t) return 0;
        x /= 10;
    }
    return 1;
}

int main() {
    int m, t, ans = 0;
    cin >> m >> t;
    for (int i = 1; i <= m; i++) {
        if (func(i, t)) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
