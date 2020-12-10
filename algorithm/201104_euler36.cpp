/*************************************************************************
	> File Name: 201104_euler36.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 04 Nov 2020 07:44:41 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//判断数x在n进制下是否为回文数
int check(int x, int n) {
    int temp = x, t = 0;
    while(x) {
        t = t * n + x % n;
        x /= n;
    }
    return t == temp;
}


int main() {
    int ans = 0;
    for (int i = 0; i < 1000000; i++) {
        if (check(i, 10) && check(i, 2)) {
            ans += i;
            cout << i << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
