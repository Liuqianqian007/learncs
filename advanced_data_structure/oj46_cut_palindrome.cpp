/*************************************************************************
	> File Name: oj46_cut_palindrome.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 19 Jan 2021 11:17:31 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

/* OJ46 切割回文
 * dp(i)表示取前i位字符时，最少分多少段，使得每段都是回文串
 * dp(i) = min(dp(j)) + 1 | s[j + 1, i] is palindrome
 * 重点是代码实现
 */

/* 基础版本，时间复杂度O(n^2)
#define MAX_N 500000
int dp[MAX_N + 5];

bool is_palindrome(string &s, int i, int j) {
    while (i < j) {
        if (s[i++] - s[j--]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    dp[0] = 0;
    for (int i = 1; i <= s.size(); i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < i; j++) {
            //dp[i]中的i代表前i段，判断回文中的i代表下标，相差1
            if (is_palindrome(s, j, i - 1)) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    cout << dp[s.size()] - 1 << endl;
    return 0;
}
*/

/* 优化：提前得到mark[j]数组，存数所有以j位置结尾的回文串的起始坐标
 * 转移时转移时利用mark数组，替代循环遍历
 * 时间复杂度：O(n + m)，m是字符串中回文串的数量
 */

#define MAX_N 500000 

vector<int> mark[MAX_N + 5];
int dp[MAX_N + 5];

int expand(string &s, int i, int j) {
    while (s[i] == s[j]) {
        //字符串坐标从0开始，dp数组从1开始
        //以j位置结尾的回文串不止一个
        mark[j + 1].push_back(i + 1);
        --i, ++j;
        if (i < 0 || j >= s.size()) break; 
    }
    return 1;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; s[i]; i++) {
        //奇数串的中心扩张
        expand(s, i, i);
        //偶数串的中心扩张
        i + 1 < s.size() && expand(s, i , i + 1);
    }
    for (int i = 1; i <= s.size(); i++) {
        dp[i] = i;
        for (int j = 0; j < mark[i].size(); j++) {
            //此处，mark[i][j]表示以i位置结尾的回文串的起始坐标中的第j个
            dp[i] = min(dp[i], dp[mark[i][j] - 1] + 1);
        }
    }
    //段数减1得到切割次数
    cout << dp[s.size()] - 1 << endl;
    return 0;
}
