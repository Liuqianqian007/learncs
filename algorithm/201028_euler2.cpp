/*************************************************************************
	> File Name: euler_2.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 28 Oct 2020 06:34:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//斐波拉契数列中偶数和-even fibonacci numbers
//三个数记录即可
int main() {
    int a = 1, b = 1, c = 2, ans = 0;
    while (c < 4000000) {
        if (c % 2 == 0) {
            ans += c;
        }
        c = b + c;
        // a = b;
        b = c - b;
    }
    cout << ans << endl;
    return 0;
}
