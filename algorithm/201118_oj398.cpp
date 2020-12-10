/*************************************************************************
	> File Name: 201118_oj398.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 18 Nov 2020 06:34:02 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

//num存答案和去重，用memset初始化为-1(因为起点的答案是0，要区分开)
int num[405][405], n, m, sx, sy;
int dir[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};

struct node {
    int x, y, step;
};


int main() {
    //memset头文件是cstring
    memset(num, -1, sizeof(num));
    cin >> n >> m >> sx >> sy;
    num[sx][sy] = 0;
    queue<node> que;
    que.push((node){sx, sy, 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            //判断边界和走过的点
            if (x < 1 || y < 1 || x > n || y > m || num[x][y] != -1) {
                continue;
            }
            //记录步数
            num[x][y] = temp.step + 1;
            que.push((node){x, y, num[x][y]});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) {
                cout << " ";
            }
            cout << num[i][j];
        }
        cout << endl;
    }

    return 0;
}
