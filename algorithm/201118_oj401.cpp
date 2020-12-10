/*************************************************************************
	> File Name: 201118_oj401.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 18 Nov 2020 06:55:56 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
//oj401——奇怪的象棋游戏升级版
//终点和起点调换，记录每个点的答案，只需要执行一次搜索

struct node {
    int x, y, step;
};

//num数组记录结果，同时标记该点是否走过
int n, num[505][505];
//方向矩阵：马走日八方向+象走田四方向
int dir[12][2] = {
    1, 2, 1, -2, -1, 2, -1, -2,
    2, 1, 2, -1, -2, 1, -2, -1,
    2, 2, 2, -2, -2, 2, -2, -2
};

int main() {
    //将结果数组num初始化为-1，因为起点的结果是0，要区分开
    memset(num, -1, sizeof(num));
    queue<node> que;
    que.push((node){1, 1, 0});
    num[1][1] = 0;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 12; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            //出界或该点已经走过，则进行下一次循环
            if (x < 1 || y < 1 || x > 500 || y > 500 || num [x][y] != -1) {
                continue;
            }
            num[x][y] = temp.step + 1;
            que.push((node) {x, y, temp.step + 1});
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << num[a][b] << endl;
    }

    return 0;
}
