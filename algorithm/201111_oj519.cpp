/*************************************************************************
	> File Name: 201111_oj519.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 11 Nov 2020 06:09:48 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//优雅数

//枚举优雅数，然后判断是否在给定区间
//不能枚举区间内的数，然后判断是否是优雅数，不然会超时

//对于优雅数XYYYY
//for循环枚举Y 0~9
//for循环枚举X 0~9
//for循环枚举数长 3~17
//for循环枚举X的位置
//判断X为0时，不在第一位
//判断Y为0时，X只在第一位


int main() {
    long long ans = 0, left, right;
    cin >> left >> right;
    //i是一堆数的数字
    //j是一个数的数字
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            //相等则不是优雅数
            if (i == j) {
                continue;
            }
            //k是数长
            for (int k = 3; k <= 17; k++) {
                for (int l = 1; l <= k; l++) {
                    if (i == 0 && l != 1) {
                        break;
                    }
                    if (j == 0 && l == 1) {
                        continue;
                    }
                    //构造
                    long long t = 0;
                    for (int m = 1; m <= k; m++) {
                        if (m == l) {
                            t = t * 10 + j;
                        } else {
                            t = t * 10 + i;
                        }
                    }
                    if (left <= t && t <= right) {
                        ans++;
                    }
                } 
            }
        }
    }

    cout << ans << endl;
    return 0;
}
