/*************************************************************************
	> File Name: 201120_oj402.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 20 Nov 2020 07:38:38 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
//奇怪的电梯
//求最少操作数——广搜

struct node {
    int now, step;
};

//check为去重数组，num为地图数组
int n, a, b, num[205], check[205];


int main() {
    //n为电梯层数，a为起始楼层，b为目标楼层
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    if (a == b) {
        cout << 0 << endl;
        return 0;
    }
    queue<node> que;
    que.push((node){a, 0});
    check[a] = 1;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        //搜索方向为上和下
        int up = temp.now + num[temp.now], down = temp.now - num[temp.now];
        //到终点
        if (up == b || down == b) {
            cout << temp.step + 1 << endl;
            return 0;
        }
        //往上不出界且没去过该层，则将往上的楼层入队且标记 
        if (up <= n && check[up] == 0) {
            que.push((node){up, temp.step + 1});
            check[up] = 1;
        }
        //往下不出界且没去过该层，则将往下的楼层入队且标记
        if (down >= 1 && check[down] == 0) {
            que.push((node){down, temp.step + 1});
            check[down] = 1;
        }
    }
    cout << -1 << endl;

    return 0;
}
