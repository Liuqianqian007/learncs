/*************************************************************************
	> File Name: 201115_oj240.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 17 Nov 2020 09:17:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//图形打印四

//len[x]表示n为x时图形的边长
//mark表示图形
int len[10] = {0, 1}, mark[3000][3000];

//初始化len数组
void init() {
    for (int i = 2; i <= 7; i++) {
        len[i] = len[i - 1] * 3;
    }
    return;
}

//初始化图形
void func(int x, int y, int n) {
    if (n == 1) {
        mark[x][y] = 'X';
        return ;
    }
    func(x, y, n - 1);
    func(x, y + len[n] / 3 * 2, n - 1);
    func(x + len[n] / 3, y + len[n] / 3, n - 1);
    func(x + len[n] / 3 * 2, y, n - 1);
    func(x + len[n] / 3 * 2, y + len[n] / 3 * 2, n - 1);
}


int main() {
    init();
    func(1, 1, 7);
    int n;
    while(cin >> n) {
        if (n == -1) return 0;
        //打印图形
        for (int i = 1; i <= len[n]; i++) {
            for (int j = 1; j <= len[n]; j++) {
                if (mark[i][j] == 'X') {
                    cout << 'X';
                } else {
                    cout << ' ';
                }
            }
            cout << endl;
        }
        cout << '-' << endl;
    }

    return 0;
}
