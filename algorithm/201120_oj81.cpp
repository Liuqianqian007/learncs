/*************************************************************************
	> File Name: 201120_oj81.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 20 Nov 2020 06:20:20 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
//小明回家


//增加f字段表示是否到过手机店：0没到过、没手机，1到过、有手机
struct node {
    int x, y, step, f;
};

//check数组去重：
//0表示没手机和有手机时都没去过
//1表示没手机时去过
//2表示有手机时去过
//3表示有没手机都去过
//(用2个二进制位对应的十进制数记录状态，可使用位运算)
int n, m, check[2005][2005];
char mmap[2005][2005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};


int main() {
    queue<node> que;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                que.push((node){i, j, 0, 0});
                check[i][j] = 1;
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            //去重：没手机时去过且当前没手机
            if ((check[x][y] & 1) && temp.f == 0) {
                continue;
            }
            //去重：有手机去过且当前有手机
            if ((check[x][y] & 2) && temp.f == 1) {
                continue;
            }
            //到终点且当前有手机,输出，并return
            if (mmap[x][y] == 'T' && temp.f == 1) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            //当前点可走且不为手机店（起点S、终点T和手机店P可能在一条直线上）
            //f保持之前的状态
            if (mmap[x][y] == '.' || mmap[x][y] == 'S' || mmap[x][y] == 'T') {
                que.push((node){x, y, temp.step + 1, temp.f});
                //当前没手机标记为1，有手机标记为2
                check[x][y] += temp.f + 1;
            }
            //到手机店：状态f改变为1；check标记为3，防止重复去手机店
            if (mmap[x][y] == 'P') {
                que.push((node){x, y, temp.step + 1, 1});
                check[x][y] = 3;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
