/*************************************************************************
	> File Name: 201104_euler30.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 04 Nov 2020 08:07:18 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//num[i]储存i^5
int num[10];
//初始化num
void init() {
    for(int i = 1; i < 10; i++) {
        int t = i;
        for (int j = 1; j < 5; j++) {
            t *= i;
        }
        num[i] = t;
    }
}

int check(int x) {
    int temp = x, t = 0;
    while(x) {
        t += num[x % 10];
        x /= 10;
    }
    return temp == t;
}


int main() {
    //init()要调用！
    init();
    int ans = 0;
    //暴力枚举
    //枚举上界：第一个使得9^5*n < 10^n成立的n,其中n为位数，这里为6，因此上界为10^6
    for (int i = 10; i < 1000000; i++) {
        if (check(i)) {
            ans += i;
            cout << i << endl;
        }
    }
    cout << ans << endl;

    return 0;
}
