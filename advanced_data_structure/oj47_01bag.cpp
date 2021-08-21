/*************************************************************************
	> File Name: oj47_01bag.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 19 Jan 2021 01:54:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* dp[i][j]表示取前i件物品，在背包最大承重为j时，得到的物品的最大价值
 * dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i])
 * （不选择第i件物品或选择第i件物品 得到的最大价值 哪个更大）
 */


/* 方法1
#define MAX_N 100  
#define MAX_V 10000
int v[MAX_N + 5], w[MAX_N + 5];
int dp[2][MAX_V + 5];

int main() {
    int V, n;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++) {
        //更新每一个dp[i][j]中的状态的值
        for (int j = 1; j <= V; j++) {
            //滚动数组，节省存储空间
            if (j < v[i]) dp[i % 2][j] = dp[(i - 1) % 2][j];
            else dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - v[i]] + w[i]);
        }
    }
    cout << dp[n % 2][V] << endl;
    return 0;
}
*/

/* 方法2
 * 变化1：去掉i这一维度，递推公式隐含由dp[]i-1[j]更新为dp[i][j]
 * 变化2：去掉v[i],w[i]数组，循环一次输入一组数据v、w
 * 变化3：第二层循环j由大到小遍历，防止覆盖掉dp[i - 1][j - v]
 * 第二层循环隐含了 if(j < v) dp[i][j] = dp[i - 1][j]
 */

#define MAX_V 10000
int dp[MAX_V + 5];

int main() {
    //V背包最大承重，n物品个数,v物品种类，w物品价值
    int V, n, v, w;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = V; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
