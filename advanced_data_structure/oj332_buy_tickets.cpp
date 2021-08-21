/*************************************************************************
	> File Name: oj332_buy_tickets.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 26 Jan 2021 06:40:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ332 买票 树状数组（前缀和）+ 二分查找（0001111）
 * 思路：跟331类似
 * 区别：
 * 1. cnt数组表示的是前面有几个数，而不是有几个比自己小的数
 * 2. 得到的ind数组表示的是val[i]排在第几位，而不是当前位置的元素值
 */

#define MAX_N 200000
#define lowbit(x) (x & -x)
int n;
//输入数组
int val[MAX_N + 5];
int cnt[MAX_N + 5];
//结果数组
int ind[MAX_N + 5];
int ans[MAX_N + 5];
//树状数组
int c[MAX_N + 5];

//树状数组单点修改
void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return;
}

//树状数组查询前缀和
int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

//二分答案（00011111）
int binary_search(int n, int x) {
    int head = 1, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (query(mid) < x) head = mid + 1;
        else tail = mid;
    }
    return head;
}

//读入数据
//cnt[i]表示第i个入队的人前面有几个人
//val表示第i个入队的人的编号
void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i] >> val[i];
        add(i, 1, n);
    }
    return;
}

//ind[i]表示第i个入队的人排在第几位，ans是结果数组
void solve() {
    for (int i = n; i >= 1; i--) {
        ind[i] = binary_search(n, cnt[i] + 1);
        add(ind[i], -1, n);
        ans[ind[i]] = val[i];
    }
    return;
}

//输出结果
void output() {
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return;
}

int main() {
    read();
    solve();
    output();
    return 0;
}
