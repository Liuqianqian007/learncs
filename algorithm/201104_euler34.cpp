/*************************************************************************
	> File Name: 201104_euler34.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 04 Nov 2020 08:29:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//将0-9的阶乘存储在num数组中
//0!=1
int num[10] = {1};

//初始化num数组
void init() {
    for (int i = 1; i < 10; i++) {
        int s = 1;
        for (int j = i; j > 0; j--) {
            s *= j;
        }
        num[i] = s;
    }
}

//比较函数
int check(int x) {
    int temp = x, sum = 0;
    while(x) {
        sum += num[x % 10];
        x /= 10;
    }
    return temp == sum;
}

int main() {
    init();
    int ans = 0;
    //计算上界：找到第一个使9!*n < 10^n成立的n，其中n为数的位数，那么上界为10^n
    for (int i = 10; i < 10000000; i++) {
        if (check(i)) {
            ans += i;
            cout << i << endl;
        }
    }
    cout << ans << endl;

    return 0;
}
