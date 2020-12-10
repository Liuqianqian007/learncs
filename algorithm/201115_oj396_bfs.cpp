/*************************************************************************
	> File Name: 201115_oj396_bfs.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 15 Nov 2020 08:46:35 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
//oj396填涂颜色
//广搜解法

//以边界填充的0为起点，搜索相邻是0的连通域，改变此连通域内的元素值为3 
//以此区分闭合圈内的0和非闭合圈内的0


//不需要记录步数，因此不用字段step
struct node {
    int x, y;
};

int n, mmap[50][50];
int dir[4][2] = {0, 1, 1, 0 , 0, -1, -1, 0};

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    //队列存放已搜索的点
    queue<node> que;
    que.push((node){0, 0});
    mmap[0][0] = 3;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            //扩张
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            //判断边界
            if (x < 0 || y < 0 || x > n + 1 || y > n + 1) {
                continue;
            }
            if (mmap[x][y] == 0) {
                mmap[x][y] = 3;
                que.push((node){x, y});
            }
        }
    }
    //输出：遇3输出0，遇1输出1，遇0输出2
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j != 1) {
                cout << " ";
            }
            if (mmap[i][j] == 3) {
                cout << 0;
            } else if (mmap[i][j] == 1) {
                cout << 1;
            } else {
                cout << 2;
            }
        }
        cout << endl;
    }

    return 0;
}
