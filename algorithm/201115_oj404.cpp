/*************************************************************************
	> File Name: 201115_0j404.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 15 Nov 2020 07:30:55 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, mark[3005][3005], ans, sx, sy;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[3005][3005];

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        //超出边界，或已被标记过
        if (xx < 1 || yy < 1 || xx > n || yy > m || mark[xx][yy] == 1) {
            continue;
        }
        //满足联通条件，则从当前点继续深搜，且标记该点
        if (mmap[x][y] != mmap[xx][yy]) {
            ans++;
            mark[xx][yy] = 1;
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    //所给地图的数字间没有空格，故输入格式为字符串
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    cin >> sx >> sy;
    ans = 1;
    mark[sx][sy] = 1;
    func(sx, sy);
    cout << ans << endl;
    return 0;
}
