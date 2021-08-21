/*************************************************************************
	> File Name: oj44_longest_ascending_subsequence.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Mon 18 Jan 2021 10:07:49 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

/* OJ44 最长上升子序列
 * 状态定义：f(i)表示以i结尾的最长上升子序列的长度
 * 状态转移：f(i) = max(f(j)) + val(i) | j < i, val(j) < val(i)
 */

/* 会超时的基础版本, 时间复杂度为O(n^2)
#define MAX_N 1000000
int arr[MAX_N + 5];
int dp[MAX_N + 5];

int main() {
    int n;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i< n; i++) {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}
*/

/* 优化：维护一个单调数组len[k]，表示长度为k的序列的末尾的最小值
 * 在len[k]数组中找到（二分查找）最后一个小于val(i) 的位置k，dp[i] = k + 1
 * 同时更新len[k + 1]的值为val(i)
 * 时间复杂度：O(n * logl)
 */

#define MAX_N 1000000 
int dp[MAX_N + 5];
int len[MAX_N + 5];

int binary_search(int *arr, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid;
    }
    return head;
}

int main() {
    int n, a, ans = 0;
    cin >> n;
    //除len[0]外都设置为极大值
    memset(len, 0x3f, sizeof(len));
    len[0] = 0;
    for (int i = 1; i <= n; i++) {
        //读入val(i)
        cin >> a;
        //找到第一个大于等于val(i)的位置
        dp[i] = binary_search(len, ans + 1, a);
        //更新len数组
        len[dp[i]] = a;
        ans = max(dp[i], ans);
    } 
    
    cout << ans << endl;
    return 0;
}
