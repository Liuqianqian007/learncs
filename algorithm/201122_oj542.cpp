/*************************************************************************
	> File Name: 201122_oj542.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 22 Nov 2020 03:19:32 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
//连通性问题——广搜深搜都可

//t数据组数，n每组数据秋的数量，h奶酪高度，r球半径
//s为起点数组，scnt为起点计数
//e为终点数组，标记是否为终点
//arr是邻接矩阵，1表示两球相通
//check是去重数组
//ball为球坐标
int t, n, h, r, s[1005],scnt, e[1005], arr[1005][1005], check[1005], ball[1005][3];

//深搜：参数为球的编号
int func(int now) {
    if (e[now] == 1) {
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[now][i] && check[i] == 0) {
            check[i] = 1;
            if (func(i)) {
                return 1;
            }
        }
    }
    return 0;
}


int main() {
    cin >> t;
    while(t--) {
        scnt = 0;
        memset(e, 0, sizeof(e));
        memset(arr, 0, sizeof(arr));
        memset(check, 0, sizeof(check));
        cin >> n >> h >> r;
        for (int i = 1; i <= n; i++) {
            cin >> ball[i][0]>> ball[i][1] >> ball[i][2];
            //起点编号加入s数组
            if (ball[i][2] <= r) {
                s[scnt++] = i;
            }
            //终点在数组e中标记为1
            if (ball[i][2] + r >= h) {
                e[i] = 1;
            }
            //生成球两两间的邻接表
            for (int j = 1; j < i; j++) {
                int x0 = ball[i][0] - ball[j][0];
                int y0 = ball[i][1] - ball[j][1];
                int z0 = ball[i][2] - ball[j][2];
                if (sqrt(x0 * x0 + y0 * y0 + z0 * z0) <= 2 * r) {
                    arr[i][j] = arr[j][i] = 1;
                }
            }
        }
        int f = 0;
        //遍历所有起点
        for (int i = 0; i < scnt; i++) {
            if (check[s[i]] == 0) {
                check[s[i]] = 1;
                if (func(s[i])) {
                    cout << "Yes" << endl;
                    f = 1;
                    break;
                }
            }
        }
        if (f == 0) {
            cout << "No" << endl;
        }
    }

    return 0;
}
