/*************************************************************************
	> File Name: euler_8.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 28 Oct 2020 07:18:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//滑动窗口求13个连续数字的乘积
//largest product in a series

char num[1005];
long long ans, zero_cnt, now = 1;

int main() {
    cin >> num;
    for (int i = 0; i < 1000; i++) {
        if (i < 13) {
            now *= num[i] - '0';
        }
        else {
            //乘0会使滑动窗口的值归零
            //且有0的窗口一定不是最大值
            //因此用zero_cnt统计当前窗口中是否有0
            if (num[i] == '0') {
                zero_cnt++;
            }
            else {
                now *= num[i] - '0';
            }
            if (num[i - 13] == '0') {
                zero_cnt--;
            }
            else {
                now /= num[i - 13] - '0';
            }
        }
        if (zero_cnt == 0) {
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}
