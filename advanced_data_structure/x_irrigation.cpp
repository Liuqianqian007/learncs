/*************************************************************************
	> File Name: irrigation.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 04 Feb 2021 11:03:51 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 【数据结构C++】 灌溉  最小生成树 
 * 步骤：
 * 1. 将所有边从小到大排序
 * 2. 依次将边加入图中，若边上两点已连通，则跳过
 * 判定两点是否连通，使用并查集
 */
#define MAX_N 10000
//定义边结构体
struct Edge {
    int v, u, c;
};
vector<Edge> e;

bool cmp(const Edge &a, const Edge &b) {
    return a.c < b.c;
}

//并查集
int fa[MAX_N + 5];
int get(int x) {
    return fa[x] = (x - fa[x] ? get(fa[x]) : x);
}
void merge(int a, int b) {
    fa[get(a)] = get(b);
}
void init(int n) {
    for (int i = 0; i <= n; i++) fa[i] = i;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a;
            if (i < j) e.push_back({i, j, a});
        }            
    }
    //边排序
    sort(e.begin(), e.end(), cmp);
    init(n);
    int ans = 0;
    for (int i = 0; i < e.size(); i++) {
        int v = e[i].v, u = e[i].u, c = e[i].c;
        if (get(v) == get(u)) continue;
        merge(v, u);
        ans += c;
    }
    cout << ans << endl;
    return 0;
}
