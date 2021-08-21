/*************************************************************************
	> File Name: oj50_throw_eggs.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 20 Jan 2021 12:16:50 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ50 扔鸡蛋：最坏情况代表运气最坏，最少代表方法最好
 * dp[n][m]表示共n个鸡蛋，楼高为m， 最坏情况下最少测k次可以测出鸡蛋硬度
 * dp[n][m] = min(max(dp[n - 1][k - 1] + 1, dp[n][m - k] + 1))
 * max表示运气最坏，碎了(dp[n - 1][k - 1])和没碎(dp[n][m - k])两种情况种选择最差的一种
 * min表示方法最好，选择一个最优的k值
 */

/* 基础方法，时间复杂度O(n * m^2)
#define MAX_N 32
#define MAX_M 1000000
int dp[MAX_N + 5][MAX_M + 5];

int main() {
    int n, m;
    cin >>n >> m;
    for (int i = 0; i <=m; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = j;
            for (int k = 1; k <= j; k++) {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i][j - k]) + 1);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
*/

/* 优化1：转移过程优化
 * 最优的k值，在dp[n - 1][k - 1] 与 dp[n][m - k]这两个函数的交点处
 * 通过寻找交点，代替通过遍历来确定最优的k值，减少一层循环
 * 时间复杂度O(n * m)

#define MAX_N 32
#define MAX_M 1000000
int dp[MAX_N + 5][MAX_M + 5];

int main() {
    int n, m;
    cin >>n >> m;
    for (int i = 0; i <=m; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        int k = 2;
        dp[i][1] = 1;
        for (int j = 2; j <= m; j++) {
            if (k < j && dp[i - 1][k - 1] < dp[i][j -k]) ++k;
            dp[i][j] = max(dp[i - 1][k - 1], dp[i][j - k]) + 1;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
*/

/* 优化2：状态定义优化（递推）
 * 因k和m正相关，可以进行转换：dp[n][m] = k  ===>  dp[n][k] = m 
 * dp[n][k]表示共n个鸡蛋，扔k次，最多可以满足多少层楼的测试需求
 * dp[n][k] = dp[n - 1][k - 1] + 1 + dp[n][k - 1]
 * 原因：m值域大，k值域小, 解决存储空间超限的问题
 */

#define MAX_N 100 
#define MAX_K 50000
long long dp[MAX_N + 5][MAX_K + 5];

int solve(int n, int m) {
    if (n == 1) return m;
    for (int i = 1; i < MAX_K; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <=MAX_K; k++) {
            dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1] + 1;
        }
    }
    int k = 1;
    while (dp[n][k] < m) k++;
    return k;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
    return 0;
}


