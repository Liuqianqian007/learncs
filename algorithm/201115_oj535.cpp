/*************************************************************************
	> File Name: 201115_oj535.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 15 Nov 2020 06:08:44 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//oj535瓷砖

//深度优先搜索，寻找连通域

int n, m, ans = 1, sx, sy;
//方向数组
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];


void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        //扩张
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        //满足条件，标记，并从该点继续搜索
        if (mmap[xx][yy] == '.') {
            ans++;
            mmap[xx][yy] = 0;
            func(xx,yy);
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            //搜索起点
            if (mmap[i][j] == '@') {
                sx = i, sy = j;
            }
        }
    }
    func(sx, sy);
    cout << ans << endl;

    return 0;
}
