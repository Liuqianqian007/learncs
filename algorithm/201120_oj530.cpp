/*************************************************************************
	> File Name: 201120_oj530.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 20 Nov 2020 08:11:31 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<string>
using namespace std;
//警察找车
//层序遍历——广搜

//对每一层搜索，分别去重（车可以反复路过一个点）

//不需要step，题意是给定step，求最终状态
struct node {
    int x, y;
};

int n, m, cnt;
//方向数组对应给定方向，北南西东
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
char mmap[55][55];

int main() {
    queue<node> que;
    cin >> n >> m;
    //输入地图
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '*') {
                que.push((node){i, j});
                //起点可以经过，改成“.”
                mmap[i][j] = '.';
            }
        }
    }
    //cnt为给定步数
    cin >> cnt;
    while (cnt--) {
        //str为给定方向
        string str;
        cin >> str;
        //用dir_num取方向数组中的某个方向
        //每层单独去重，因此check数组定义在循环内（记得初始化）
        int dir_num, check[55][55] = {0}, qsize = que.size();
        if (str == "NORTH") {
            dir_num = 0;
        } else if(str == "SOUTH") {
            dir_num = 1;
        } else if(str == "WEST") {
            dir_num = 2;
        } else {
            dir_num = 3;
        }
        //一层一层出队，留最后一层为结果，因此每个方向循环qsize次
        while (qsize--) {
            node temp = que.front();
            que.pop();
            //i是距离
            for (int i = 1; 1; i++) {
                int x = temp.x + dir[dir_num][0] * i;
                int y = temp.y + dir[dir_num][1] * i;
                //出界或遇障碍
                if (mmap[x][y] != '.') {
                    break;
                }
                //一层内也需要去重，因为从第三步开始可能有大量重复
                if (check[x][y] == 0) {
                    que.push((node){x, y});
                    check[x][y] = 1;
                }
            }
        }
    }
    //最后剩的一层的队列中的点就是所求点，改为*
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        mmap[temp.x][temp.y] = '*';
    }
    //输出答案
    for (int i = 1; i <= n; i++) {
        cout << &mmap[i][1] << endl;
    }

    return 0;
}
