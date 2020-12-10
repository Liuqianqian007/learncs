/*************************************************************************
	> File Name: 201115_oj536.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 15 Nov 2020 06:35:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//oj536最大黑色区域

//temp记录每个连通域的大小
int n, m, ans, temp;
//0和1挨着的，所以输入的是字符，不是数字
char mmap[105][105];

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        //扩张
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        //满足条件从该点继续搜索，并标记，以免重复搜索
        if (mmap[xx][yy] == '1') {
            temp++;
            mmap[xx][yy] = 0;
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        //按行输入字符串，从1开始输入，边界自动补0
        cin >> &mmap[i][1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //该点为1则作为深搜起点
            if (mmap[i][j] == '1') {
                temp = 1;
                mmap[i][j] = 0;
                func(i, j);
                ans = max(ans, temp);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
