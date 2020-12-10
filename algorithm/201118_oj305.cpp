/*************************************************************************
	> File Name: 201118_oj305.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 18 Nov 2020 07:38:27 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
//此题输入的行列n，m是反的
struct node {
    int x, y, step;
};

//八个方向
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

int n, m, sx, sy, ans;
char mmap[105][105];

int main() {
    cin >> m >> n >>sy >> sx;
    //起点在地图中是左下角，且给定起点的横纵坐标是反的
    sx = n - sx + 1;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    queue<node> que;
    que.push((node){sx, sy, 0});
    mmap[sx][sy] = 0;
    while (!que.empty()) {
        node temp = que.front();
        //最后一个搜到的点是最远的点
        ans = temp.step;
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '.') {
                mmap[x][y] = 0;
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
