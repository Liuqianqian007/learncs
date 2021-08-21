/*************************************************************************
	> File Name: oj49_multiple_bag.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 19 Jan 2021 11:51:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ49 多重背包：每种物品数量为有限多个
 * 转换为01背包，把s个同种物品转换为s种物品，增加一层循环 
 */

/* 基础版本
#define MAX_V 100000
int dp[MAX_V + 5];

int main() {
    //V背包承重，n物品种类，v物品重量，w物品价值，s物品个数
    int V, n, v, w, s;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w >> s;
        for (int k = 0; k < s; k++) {
            for (int j = V; j >= v; j--) {
                dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
*/

/* 优化1：由单个拆分变成二进制拆分
 * 示例：14件物品本来拆成14种单个物品，现在拆成1、2、4、7共4种物品，也可满足1~14的组合
 * 时间复杂度：O(n * v * logs)
 * 多重背包的最优时间复杂度是O(nm)，使用单调队列
 */

#define MAX_V 100000
int dp[MAX_V + 5];

int main() {
    //V背包承重，n物品种类，v物品重量，w物品价值，s物品个数
    int V, n, v, w, s;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w >> s;
        for (int k = 1; s; k = k * 2) {
            if (k > s) k = s;
            s -= k;
            for (int j = V; j >= k * v; j--) {
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
