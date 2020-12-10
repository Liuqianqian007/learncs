/*************************************************************************
	> File Name: 201101_oj391.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 01 Nov 2020 07:16:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//二分答案
//0000111

long long n, m, num[100005], tl, tr;

//通过输入的最大值统计段数
long long func(long long x) {
    long long cnt = 0, now = 0;
    for (int i = 0; i < n; i++) {
        if (now + num[i] == x) {
            cnt++;
            now = 0;
        } else if (now + num[i] > x) {
            cnt++;
            now = num[i];
        } else {
            now += num[i];
        }
    }
    //判断最后一段是否统计
    if (now) {
        cnt++;
    }
    return cnt;
}

long long bin_search() {
    //二分边界：所求分段最大值的下界是单个元素中的最大值，上界是所有元素之和
    long long l = tl, r = tr;
    while (l != r) {
        long long mid = (l + r) / 2;
        long long s = func(mid);
        if (s <= m) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tl = max(tl, num[i]);
        tr += num[i];
    }
    cout << bin_search() << endl;

    return 0;
}
