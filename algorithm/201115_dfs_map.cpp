/*************************************************************************
	> File Name: 201115_dfs_map.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 27 Nov 2020 12:40:22 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, sx, sy;
char mmap[105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        //遇到终点则return 1
        if (mmap[xx][yy] == 'T') {
            return 1;
        }
        //遇到可通行的.则标记为#防止重复走，并进行下一轮深搜
        if (mmap[xx][yy] == '.') {
            mmap[xx][yy] = '#';
            if (func(xx, yy) == 1) {
                return 1;
            }
        }
    }
}


int main() {
    cin >> n >> m;
    //输入数据并标记起点，外圈补零
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    if (func(sx, sy) == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
