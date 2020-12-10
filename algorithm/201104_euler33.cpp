/*************************************************************************
	> File Name: 201104_euler33.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 04 Nov 2020 07:19:08 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int check(int a, int b) {
    int x1 = a / 10, x2 = a % 10;
    int y1 = b / 10, y2 = b % 10;
    //排除平凡解
    if (!x2 || !y2) return 0;
    //判断两个分数是否相等，交叉相乘
    if (x1 == y1 && a * y2 == b * x2) return 1;
    if (x2 == y1 && a * y2 == b * x1) return 1;
    if (x1 == y2 && a * y1 == b * x2) return 1;
    if (x2 == y2 && a * y1 == b * x1) return 1;
    return 0;
}

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    //a为结果分子，b为结果分母
    int a = 1, b = 1;
    for (int i = 11; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (check(i, j)) {
                a *= i;
                b *= j;
                //输出非平凡解
                cout << i << " / " << j << endl;
            }
        }
    }
    //分母除以最大公约数
    int x = gcd(a, b);
    cout << b / x << endl;

    return 0;
}
