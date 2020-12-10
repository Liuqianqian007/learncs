/*************************************************************************
	> File Name: bfs_map.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 15 Nov 2020 08:29:40 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
/*
输入数据：S为起点，T为终点
S...
##..
##..
T...
*/

//广度优先搜索, oj399
//解决问题一：连通性问题
//解决问题二：最短路径问题

//结构体记录当前点坐标和走到当前点用的步数
struct node {
    int x, y, step;
};

int n, m, sx, sy;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];

int main() {
    cin >> n >> m;
    //输入数据并记录起点坐标
    for (int i = 1; i <= n; i++) {
        for (int j = 1;j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    //队列记录已搜索过的点
    queue<node> que;
    que.push(node({sx, sy, 0}));
    while (!que.empty()) {
        //队列不为空则每次从队首取出一个点扩张
        node temp = que.front();
        que.pop();
        //扩张：遍历上右下左四个方向
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            //找到终点，输出步数并返回
            if (mmap[x][y] == 'T') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            //如果是可走的点，则标记避免重复，并加入队列
            if (mmap[x][y] == '.') {
                mmap[x][y] = 0;
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    //队列遍历结束还没找到终点
    cout << "NO" << endl;
    return 0;
}
