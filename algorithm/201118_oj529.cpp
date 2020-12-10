/*************************************************************************
	> File Name: 201118_oj529.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 18 Nov 2020 07:54:35 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
//oj529——龙与虫

//先标记出所有能消灭敌人的位置，然后从起点广搜找到第一个能消灭敌人的位置

struct node {
    int x, y, step;
};

int n, m;
//用一个数组存方向数组即可，遍历0~3为四方向，遍历0~7为八方向
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, -1, 1, 1, -1, -1, -1};
char mmap[150][150];

int func() {
    //a,b为敌人位置，c,d为起始位置
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    //输入结束
    if (!a) return 0;
    //多次询问，不能改原地图
    //另开一个数组mark用来标记可以消灭敌人的位置（标为1），以及已经搜索过的位置（标为2）
    int mark[150][150] = {0};
    //标记可以消灭敌人的位置：八方向遍历，不能出界且未遇到障碍
    for (int i = 0; i < 8; i++) {
        for (int j = 1; 1; j++) {
            int x = a + dir[i][0] * j;
            int y = b + dir[i][1] * j;
            //有障碍或出界则跳过此方向
            if (mmap[x][y] != 'O') break;
            mark[x][y] = 1;
        }
    }
    mark[a][b] = 1;
    //如果起始位置就是能消灭敌人的位置
    if (mark[c][d] == 1) {
        cout << 0 << endl;
        return 1;
    }
    queue<node> que;
    que.push((node){c, d, 0});
    mark[c][d] = 2;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            //走到可以消灭敌人的位置，输出并返回
            if (mark[x][y] == 1) {
                cout << temp.step + 1 << endl;
                return 1;
            }
            //不是障碍，未出界且没走过，则入队，并标记为2，避免重复走
            if (mmap[x][y] == 'O' && mark[x][y] != 2) {
                que.push((node){x, y, temp.step + 1});
                mark[x][y] = 2;
            }
        }
    }
    cout << "Impossible!" << endl;
    return 1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    //多次输入，不能直接在主函数return
    //不用func的话，得到一次输入的结果后需要跳出两层循环，比较麻烦
    while (func()) {}
    return 0;
}
