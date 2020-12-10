/*************************************************************************
	> File Name: 201101_oj393.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 01 Nov 2020 06:19:53 PM CST
 ************************************************************************/

#include<iostream>
#include <cstdio>
using namespace std;
//二分答案

int n,m;
double num[10005], tr;

//func函数传入题目要求解的变量，返回题目中给定的限制变量
int func(double len) {
    int s = 0;
    for (int i = 0; i < n; i ++) {
        s += num[i] / len;
    }
    return s;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);
    }
    double l = 0, r = tr;
    while(r - l > 0.00001) {
        double mid = (l + r) / 2;
        int s = func(mid);
        //浮点数的边界更新都为mid
        if (s >= m) {
            l = mid;
        } else {
            r = mid;
        }
    }

    //保留2位小数，直接舍弃2位后的小数
    printf("%.2f\n", (int)(l * 100) / 100.0);
    return 0;
}
