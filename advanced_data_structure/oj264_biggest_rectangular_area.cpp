/*************************************************************************
	> File Name: oj264_biggest_rectangular_area.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 22 Jan 2021 11:20:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ264 最大矩形面积-单调栈-最近大于/小于关系
 * 遍历每一块木板，寻找左右第一个小于其高度的木板
 * 单调栈中记录下标而不是元素值，因为由下标可索引到值
 * 均摊时间复杂度O(1)
 */

#define MAX_N 100000
//s是单调栈，h记录木板高度, l记录左边第一个小于当前木板高度的坐标，r记录右边的
long long s[MAX_N + 5], top;
long long h[MAX_N + 5], n;
long long l[MAX_N + 5], r[MAX_N + 5];

void read() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &h[i]);
    return;
}

long long solve() {
    //将首尾加上高度为-1的木板，方便处理
    h[0] = h[n + 1] = -1;
    //求左边最近的小于当前元素的坐标
    top = -1;
    s[++top] = 0;
    for (int i = 1; i <= n; i++) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        l[i] = s[top];
        s[++top] = i;
    }
    //求右边最近的小于当前元素的坐标
    top = -1;
    s[++top] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, h[i] * (r[i] - l[i] - 1));
    }
    return ans;
}

int main() {
    read();
    cout << solve() << endl;

    return 0;
}
