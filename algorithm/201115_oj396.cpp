/*************************************************************************
	> File Name: 201115_oj396.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 15 Nov 2020 06:52:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//oj396填涂颜色

//已边界填充的0作为深搜起点，找到边界0的连通域内的0，标记为3
//则未标记的0则是闭合圈内的0

int n, mmap[50][50];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

//深搜
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        //扩张
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        //超出边界
        if (xx < 0 || yy < 0 || xx > n + 1 || yy > n + 1) {
            continue;
        }
        //递归，该点满足条件则继续深搜
        if (mmap[xx][yy] == 0) {
            mmap[xx][yy] = 3;
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    mmap[0][0] = 3;
    //深度搜索，起点是（0，0）
    func(0, 0);
    //输出答案
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j != 1) {
                cout << " ";
            }
            if (mmap[i][j] == 3) {
                cout << 0;
            } else if (mmap[i][j] == 0) {
                cout << 2;
            } else {
                cout << 1;
            }
        }
        cout << endl;
    }

    return 0;
}
