/*************************************************************************
	> File Name: 201115_oj397.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 15 Nov 2020 06:23:00 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//oj397僵尸来袭——利用深搜寻找连通域

//mmap为题目所给的地图数组
int n, m, ans, mmap[105][105];
//方向数组，上右下左
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
//深度优先搜索
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] != 0) {
            //找到目标元素则置0，防止重复搜索
            mmap[xx][yy] = 0;
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    //输入地图
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    
    for (int i = i; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //遇到不为0的元素则说明是另一个连通域，因此可作为搜索起点
            if (mmap[i][j] != 0) {
                ans++;
                mmap[i][j] = 0;
                func(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
