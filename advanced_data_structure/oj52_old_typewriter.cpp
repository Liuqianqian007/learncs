/*************************************************************************
	> File Name: oj52_old_typewriter.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 23 Jan 2021 07:14:42 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ52 古老的打字机 单调队列 
 * dp[i]代表打印前i个字符的最小消耗
 * dp[i] = min(dp[j] + ΣC(k)) + M , k = [j + 1, i]
 * dp[i] = min(dp[j] + (sum(i) - sum(j))^2 + M), sum(j)为C(1)~C(j)的前缀和
 * 时间复杂度O(n^2), 会超时
 *
 * 优化：斜率优化，时间复杂度变为O(n)
 */

#define MAX_N 1000000
#define S(a) ((a) * (a))
//dp数组记录动态规划过程，f记录转移项，s记录前缀和
long long  dp[MAX_N + 5], f[MAX_N + 5], s[MAX_N + 5];
//c记录消耗值(可去掉，用s存储)，M是固定小号，n是字符个数
int c[MAX_N + 5], M, n;
//q是单调队列
int q[MAX_N + 5], head, tail;

//求斜率
double slope(int i, int j) {
    return 1.0 * (f[i] - f[j]) / (s[i] - s[j]);
}

//读入消耗值c，并计算前缀和s
void read() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        s[i] = s[i - 1] + c[i];
    }
    return;
}

//状态转移：从i转移到j，并求转移项f
void set_dp(int i, int j) {
    dp[i] = dp[j] + S(s[i] - s[j]) + M;
    f[i] = dp[i] + S(s[i]);
    return;
}

long long solve() {
    head = tail = 0;
    q[tail++] = 0;
    for (int i = 1; i <= n; i++) {
        //队首出队
        while (tail - head >= 2 && slope(q[head + 1], q[head]) < 2 * s[i]) head++;
        set_dp(i, q[head]);
        //去掉拱形斜率的中间那个点
        while(tail - head >= 2 && slope(i, q[tail - 1]) < slope(q[tail - 2], q[tail - 1])) --tail;
        q[tail++] = i;
    }
    return dp[n];
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
