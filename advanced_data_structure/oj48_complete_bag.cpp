/*************************************************************************
	> File Name: oj48_complete_bag.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 19 Jan 2021 11:23:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ48 完全背包，每种物品有若干件
 * dp[i][j]表示取前i种物品，当背包容量为j时，得到物品的最大价值
 * dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i])
 * 不选择第i种物品或选择若干件第i种物品，哪个价值更大
 */

#define MAX_V 10000
int dp[MAX_V + 5];
int main() {
    int n, V, v, w;
    cin >> n >> V;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        //与01背包的区别：循环时正序遍历j 
        //使得dp[j - v]表示的是dp[i][j - v] 而不是dp[i - 1][j - v]
        for (int j = v; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << endl;

    return 0;
}
