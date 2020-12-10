/*************************************************************************
	> File Name: 201122_oj541.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Mon 23 Nov 2020 11:25:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//arr储存两个人的邻接矩阵（存两点间的行走时间）
//ans储存两个人的答案（行走时间），2^16 = 65536，因此大小开100000
//cnt储存两个人的答案数
int n, m, arr[2][20][20], ans[2][100000], cnt[2];

//pnum 第几个人
//now 当前第几个点
//cost 到目前为止花费的时间
void func(int pnum, int now, int cost) {
    //当前走到了终点，ans答案数组中增加一个记录
    if (now == n) {
        ans[pnum][cnt[pnum]++] = cost;
        return;
    }
    //只能从小数走到大数
    for (int i = now + 1; i <= n; i++) {
        //两点之间有路
        if (arr[pnum][now][i] != 0) {
            func(pnum, i, cost + arr[pnum][now][i]);
        }
    }
}


int main() {
    cin >> n >> m;
    //生成邻接矩阵
    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[0][a][b] = arr[0][b][a] = c;
        arr[1][a][b] = arr[1][b][a] = d;
    }
    //得到第一个人的所有行走时间
    func(0, 1, 0);
    //得到第二个人的所有行走时间
    func(1, 1, 0);
    //定义一个极大值
    int fin = 2100000000;
    //选择两个答案数组中都有的最小的数
    for (int i = 0; i < cnt[0]; i++) {
        if (fin < ans[0][i]) {
            continue;
        }
        for (int j = 0; j < cnt[1]; j++) {
            if (ans[0][i] == ans[1][j]) {
                fin = ans[0][i];
            }
        }
    }
    if (fin == 2100000000) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << fin << endl;
    }
    return 0;
}
