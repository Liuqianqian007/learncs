/*************************************************************************
	> File Name: 201115_oj405.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 15 Nov 2020 07:44:51 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

//ans数组同时作为标记数组和答案数组
//cnt记录某个连通域的队列的长度，即该连通域中元素的个数
int n, m, k, ans[3005][3005], cnt;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[3005][3005];

struct node {
    int x, y;
};
queue<node> que;

//用数组ans保存元素所在连通域的元素个数
void check() {
    while (!que.empty()) {
        node t = que.front();
        que.pop();
        ans[t.x][t.y] = cnt;
    }
}

//深度优先搜索
void func(int x, int y) {
    //将该连通域的每个点都入队
    que.push(node({x, y}));
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        //超出边界，或（xx, yy）已被标记过，即已属于某个连通域，则寻找下一个方向
        if (xx < 1 || yy < 1 || xx > n || yy > m || ans[xx][yy] != 0) {
            continue;
        }
        //符合联通条件，即相邻元素不相等，则标记，并继续搜索
        if (mmap[x][y] != mmap[xx][yy]) {
            ans[xx][yy] = 1;
            func(xx, yy);
        }
    }
}


int main() {
    cin >> n >> m >> k;
    //给定地图的数字是相连的，因此输入格式为字符串
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //如果该点没被标记过，即还不属于任何连通域，则将这点作为深搜起点，并标记
            if (ans[i][j] == 0) {
                ans[i][j] = 1;
                func(i, j);
                //记录深搜得到的连通域队列的长度，即要求的结果
                cnt = que.size();
                //将每点的结果存入数组
                check();
            }
        }
    }
    //输出答案
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        cout << ans[a][b] << endl;
    }
    return 0;
}
