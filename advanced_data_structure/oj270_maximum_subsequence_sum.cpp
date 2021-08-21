/*************************************************************************
	> File Name: oj270_maximum_subsequence_sum.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 23 Jan 2021 11:11:13 PM CST
 ************************************************************************/

#include<iostream>
#include<climits>
using namespace std;

/* OJ270 最大子序和-单调队列
 * S(i)代表前i个元素的前缀和，连续子序列和可转化为S(i) - S(j)
 * 以i位置结尾的窗口内连续子序列和最大即可转化为窗口内S(j)最小
 */

#define MAX_N 300000
//前缀和s
int s[MAX_N + 5], n, m;
//q是单调队列，保存窗口内前缀和s最小值
int q[MAX_N + 5], head, tail;

void read() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    return;
}

int solve() {
    int ans = INT_MIN;
    head = tail = 0;
    q[tail++] == 0;
    for (int i = 1; i <= n; i++) {
        //队首出队
        if (i - q[head] > m) head++;
        ans = max(ans, s[i] - s[q[head]]);
        while (tail - head && s[q[tail - 1]] > s[i]) --tail;
        q[tail++] = i;
    }
    return ans;
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
