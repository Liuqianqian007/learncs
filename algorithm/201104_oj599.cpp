/*************************************************************************
	> File Name: 201104_oj599.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 04 Nov 2020 08:31:56 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
//两数之和1
//双指针

int num[1000005];

int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        //数据太多，用cin可能会超时
        scanf("%d", &num[i]);
    }
    int l = 0, r = n - 1;
    while (l < r) {
        if (num[l] + num[r] == t) {
            printf("%d %d\n", l, r);
            return 0;
        } else if (num[l] + num[r] > t) {
            r--;
        } else {
            l++;
        }
    }
    printf("%d\n", -1);
    return 0;
}
