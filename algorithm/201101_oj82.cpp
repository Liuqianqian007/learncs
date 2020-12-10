/*************************************************************************
	> File Name: 201101_oj82.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 01 Nov 2020 06:42:12 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, num[1000005], tr;
//int类型的最大值是2开头的十位数
long long func(int h) {
    long long s = 0;
    for (int i = 0; i < n; i++) {
        if (h < num[i]) {
            s += num[i] - h;
        }
    }
    return s;
}


int bin_search() {
    int l = 0, r = tr;
    while (l != r) {
        int mid = ((long long)l + r + 1) / 2;
        long long s = func(mid);
        if (s >= m) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    return r;
} 


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);
    }
    cout << bin_search() << endl;
    return 0;
}
