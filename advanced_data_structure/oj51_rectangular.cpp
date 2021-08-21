/*************************************************************************
	> File Name: oj51_rectangular.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 23 Jan 2021 04:57:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ51 矩形 动态规划+单调栈
 *
 *
 */

#define MAX_N 1000
#define MOD_NUM 100007
//s是单调栈，存储每点左边最近的小于自身的元素的位置
//c[i][j]记录(i, j)往上有多少个连续的白色格子，即高度
//f[i][j]记录以(i, j)为右下角坐标的矩形个数
//f[i][j] = c[i][j] * (j - k) + f[i][k]，其中k代表(i, j) 左侧最近的c值小于自身的元素的位置，即s的栈顶
int s[MAX_N + 5],top;
int c[MAX_N + 5][MAX_N + 5];
int f[MAX_N + 5];
int n, m;

void read() {
    cin >> n >>m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j]) c[i][j] += c[i - 1][j];
        }
    }
    return;
}

long long  solve() {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        top = -1;
        s[++top] = 0;
        c[i][0] = -1;
        f[0] = 0;
        for (int j = 1; j <= m; j++) {
            while (top != -1 && c[i][s[top]] >= c[i][j]) --top;
            //求以每点为右下角坐标的矩形数量
            f[j] = c[i][j] * (j - s[top]) + f[s[top]];
            //入栈
            s[++top] = j;
            ans += f[j];
            //答案模100007后再输出
            ans %= MOD_NUM;
        }
    }
    return ans;
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
