/*************************************************************************
	> File Name: 201104_euler32.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 04 Nov 2020 06:31:37 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;


//判断数字位数
int digit(int x) {
    return (int)floor(log10(x)) + 1;
}
//标记出现过的数字
//return 0表示有重复
//return 1表示无重复，符合题意
int check(int x, int* num) {
    while (x) {
        if (num[x % 10] == 1) {
            return 0;
        } else {
            num[x % 10] = 1;
            x /= 10;
        }
    }
    return 1;
}

int func(int a, int b, int c) {
    //用num数组标记出现过的数字为1
    //将num[0]初始化为1，表示0出现则返回false
    int num[10] = {1};
    if (check(a, num) == 0) return 0;
    if (check(b, num) == 0) return 0;
    if (check(c, num) == 0) return 0;
    return 1;
}

int main() {
    int ans = 0, mark[10005];
    //第一个数小于第二个数,以避免重复遍历
    //第一个数小于100，否则乘积至少为5位数，那么三个数一共11位了
    for (int i = 1; i < 100; i++) {
        for (int j = i + 1; 1; j++) {
            int a = digit(i), b = digit(j), c = digit(i * j);
            if (a + b + c == 9) {
                if (func(i, j, i * j)) {
                    //用mark数组标记答案，避免重复
                    if (mark[i * j] == 0) {
                        ans += i * j;
                        mark[i * j] = 1;
                    }
                    cout << i << " * " << j << " = " << i * j << endl;
                }
            //第二个乘数结束遍历
            } else if (a + b + c > 9) {
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
