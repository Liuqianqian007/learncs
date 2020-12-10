/*************************************************************************
	> File Name: 201118_oj527.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 18 Nov 2020 08:27:11 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
//增加字段d表示在该点所剩的飞行距离（能量）
struct node {
    int x, y, step, d;
};

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
//mark数组表示当前坐标(x, y)，所剩飞行距离（能量）为z时，是否走到过，走过则标记为1。前两维是坐标，第三维是所剩能量
int m, n, d, mark[105][105][105];
char mmap[105][105];


int main() {
    cin >> m >> n >> d;
    //m是行
    for (int  i = 1; i <= m; i++) {
        cin >> &mmap[i][1];
    }
    queue<node> que;
    que.push((node){1, 1, 0, d});
    //全部能量状态下的起点坐标都标记为1
    for (int i = 0; i <= d; i++) {
        mark[1][1][i] = 1;
    }

    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        //四个方向扩散
        for (int i = 0; i < 4; i++) {
            //该方向先飞行
            for (int j = 2; j <= temp.d; j++) {
                int x = temp.x + dir[i][0] * j;
                int y = temp.y + dir[i][1] * j;
                //出界就不往这个方向飞了
                if (x < 1 || y < 1 || x > m || y > n) {
                    break;
                }
                //到达终点，输出步数，并结束
                if (x == m && y == n) {
                    cout << temp.step + 1 << endl;
                    return 0;
                }
                //是平原P且该点该能量状态下未被标记过，则标记，且入队
                //注意要减去这一步用的能量
                if (mmap[x][y] == 'P' && mark[x][y][temp.d - j] == 0) {
                    que.push((node){x, y, temp.step + 1, temp.d - j});
                    mark[x][y][temp.d - j] = 1;
                }
            }
            //该方向走一步
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            //到终点
            if (x == m && y == n) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            //是平原P且该点该能量状态下未被标记过，则标记，且入队
            //走一步不需要判断边界
            if (mmap[x][y] == 'P' & mark[x][y][temp.d] == 0) {
                que.push((node){x, y, temp.step + 1, temp.d});
                mark[x][y][temp.d] = 1;
            }
        }
    }
    //遍历结束还未到终点
    cout << "impossible" << endl;
    return 0;
}
