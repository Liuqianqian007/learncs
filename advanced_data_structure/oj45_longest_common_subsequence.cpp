/*************************************************************************
	> File Name: oj45_longest_common_subsequence.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Mon 18 Jan 2021 10:57:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ45 最长公共子序列
 * 状态定义：f(i, j)代表第1个字符串取前i位，第2个字符串取前j位的最长公共子序列的长度
 * 状态转移：f(i, j) = max(f(i - 1, j), f(i, j - 1)) | s1(i) != s2(j)
 *           f(i, j) = f(i - 1, j - 1) + 1 | s1(i) == s2(j)
 * 重点：参与决策的状态数量随着条件条件而改变
 * 时间复杂度：O(n*m)
 */

string s1, s2;
#define MAX_N 1000
int dp[MAX_N + 5][MAX_N + 5] = {0};

int main() {
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}
