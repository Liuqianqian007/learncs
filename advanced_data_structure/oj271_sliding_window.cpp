/*************************************************************************
	> File Name: oj271_sliding_window.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 22 Jan 2021 01:09:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ271 滑动窗口-单调队列
 * 给定一个数组，输出滑动窗口内的最小值和最大值
 * 均摊时间复杂度O(1)
 */

#define MAX_N 300000
//q为单调队列，记录数组下标，val为给定数组
int q[MAX_N + 5], head = 0, tail = 0;
int val[MAX_N + 5];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    //输出滑动窗口内的最小值
    for (int i = 1; i <= n; i++) {
        //入队，把大于当前元素的元素出队
        while (tail - head && val[q[tail - 1]] > val[i]) --tail;
        q[tail++] = i;
        //超过窗口大小，出队
        if (q[head] <= i - k) head++;
        if (i >= k) {
            i > k && cout << " ";
            cout << val[q[head]];
        }
    }
    cout << endl;

    head = tail = 0;
    //输出滑动窗口内的最大值
    for (int i = 1; i <= n; i++) {
        //入队，把小于当前元素的元素出队
        while (tail - head && val[q[tail - 1]] < val[i]) --tail;
        q[tail++] = i;
        //超过窗口大小，出队
        if (q[head] <= i - k) head++;
        if (i >= k) {
            i > k && cout << " ";
            cout << val[q[head]];
        }
    }
    cout << endl;

    return 0;
}
