/*************************************************************************
	> File Name: 201118_oj303.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 18 Nov 2020 07:19:49 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
//oj303
//起点和终点调换

struct node {
    int x, y, step;
};
//num数组存结果，同时标记是否已走过
int n, m, num[1005][1005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[1005][1005];

int main() {
    memset(num, -1, sizeof(num));
    cin >> n >> m;
    queue<node> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            //所有1都是起点，全部入队
            if (mmap[i][j] == '1') {
                que.push((node){i, j, 0});
                num[i][j] = 0;
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            //不是边界且没有走到过则可以走
            if (mmap[x][y] != 0 && num[x][y] == -1) {
                num[x][y] = temp.step + 1;
                que.push((node){x, y, num[x][y]});
            }
        }
    }
    for (int i = 1; i<= n; i++) {
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
