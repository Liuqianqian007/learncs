/*************************************************************************
	> File Name: 201125_oj387.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 25 Nov 2020 10:45:41 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
//吃瓜群众升级版
//特殊二分0000111
struct node {
    int cnt, num;
};

bool cmp(const node &a, const node &b) {
    return a.num < b.num;
}

int n, m;
node wm[100005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> wm[i].num;
        wm[i].cnt = i + 1;
    }
    //找不到时，输出第n堆瓜的编号0
    wm[n].cnt = 0;
    wm[n].num = 2100000000;
    sort(wm, wm + n + 1, cmp);
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n;
        cin >> t;
        while (l != r) {
            int mid = (l + r) / 2;
            if (wm[mid].num >= t) {
                r =  mid;
            } else {
                l = mid + 1;
            }
        }
        cout << wm[l].cnt << endl;
    }
    return 0;
}
