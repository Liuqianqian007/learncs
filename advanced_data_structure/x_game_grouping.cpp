/*************************************************************************
	> File Name: game_grouping.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 04 Feb 2021 10:32:20 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
/* 【数据机构C++】 游戏分组 并查集 */

#define MAX_N 1000000
int fa[MAX_N + 5];

//路径压缩
int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));

}

//融合
void merge(int a, int b) {
    fa[get(a)] = get(b);
    return ;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) fa[i] = i;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        merge(a, b);
    }
    int ans = 0;
    //统计集合数目
    for (int i = 0; i < n; i++) {
        ans += (fa[i] == i);
    }
    cout << ans << endl;
    return 0;
}

