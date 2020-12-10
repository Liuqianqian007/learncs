/*************************************************************************
	> File Name: 201101_oj390.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 25 Nov 2020 11:04:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//二分答案1111000

//lr是最长的那根木头长度
int n, m, num[100005], lr;

//传入长度，求可切出多少段
int func(int len) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += num[i] / len;
    }
    return s;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        lr = max(lr, num[i]);
    }
    //二分边界
    int l =  1, r = lr;
    //二分
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;

    return 0;
}
