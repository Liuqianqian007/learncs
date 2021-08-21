/*************************************************************************
	> File Name: simplified_shortest_path.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 04 Feb 2021 10:23:57 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/* 【数据结构C++】 最短路简化版 广搜 */

#define MAX_N 1000
int g[MAX_N + 5][MAX_N + 5];

//建立邻接表
inline void add(int a, int b) {
    g[a][++g[a][0]] = b;
    g[b][++g[b][0]] = a;
    return ;
}
int ans[MAX_N + 5];

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        add(a, b);
    }
    queue<int> q;
    ans[c] = 1;
    q.push(c);
    while (!q.empty()) {
        int ind = q.front();
        for (int i = 1; i <= g[ind][0]; i++) {
            int to = g[ind][i];
            if (ans[to]) continue;
            ans[to] = ans[ind] + 1;
            q.push(to);
        }
        q.pop();
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] - 1 << endl;
    }    
    return 0;

}
