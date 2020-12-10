/*************************************************************************
	> File Name: 201108_oj517.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 08 Nov 2020 08:40:52 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, ans;

int main() {
    cin >> n;
    //枚举长度递增
    //最短边范围1~n/3,中长边范围i~（n-i）/2，最长边为n-i-j
    for (int i  = 1; i <= n / 3; i++) {
        for (int j = i; j <= (n - i) / 2; j++) {
            if (i + j > n - i - j) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
