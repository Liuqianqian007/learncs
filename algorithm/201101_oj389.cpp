/*************************************************************************
	> File Name: 201101_oj389.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 25 Nov 2020 11:28:23 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
//二分答案11110000

int n, m, num[100005], tr;

//传入间隔距离，返回能安排的人数
int func(int d) {
    int s = 1, last = num[0];
    for (int i = 1; i < n; i++) {
        if (num[i] - last >= d) {
            s++;
            last = num[i];
        }
    }
    return s;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);
    }
    sort(num, num + n);
    //二分边界
    int l = 1, r = tr; 
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
    return 0;
}
