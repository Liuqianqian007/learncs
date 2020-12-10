/*************************************************************************
	> File Name: 201118_oj304.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 18 Nov 2020 06:17:58 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

struct node {
    int x, y, step;
};

int n, m;
//方向数组变化(马走日八方向)
int dir[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};
char mmap[200][200];


int main() {
    cin >> m >> n;
    queue<node> que;
    //读入数据补0不止补一圈
    for (int i = 5; i < n + 5; i++) {
        for (int j = 5; j < m + 5; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'K') {
                que.push((node){i, j, 0});
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        //向八个方向扩散
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            //到达终点
            if (mmap[x][y] == 'H') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.') {
                que.push((node){x, y, temp.step + 1});
                mmap[x][y] = '#';
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
