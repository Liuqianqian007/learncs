/*************************************************************************
	> File Name: 201030_oj590.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 30 Oct 2020 08:26:40 PM CST
 ************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;
//树塔狂想曲——Euler18进阶

//num：树塔的原数据
//utd：从上往下走每点的最大路径和， dtu：从下往上走每点的最大路径和
//ans：经过点（x，y）的完整路径的最大路径和
//mmax：每行的最大值坐标mmax[i][0]和次大值mmax[i][1]
int n, m, num[1005][1005], utd[1005][1005], dtu[1005][1005], ans[1005][1005], mmax[1005][2];

int main() {
    scanf("%d%d", &n, &m);
    //输入数据,外圈补零
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    //从上往下走
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            utd[i][j] = max(utd[i - 1][j - 1], utd[i - 1][j]) + num[i][j];
        }
    }
    //从下往上走
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            dtu[i][j] = max(dtu[i + 1][j], dtu[i + 1][j + 1]) + num[i][j];
        }
    }
    //经过每点的最大路径和
    for (int i = 1; i <=  n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = utd[i][j] + dtu[i][j] - num[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        //cnt：每层的最大值坐标
        //m1：每层的最大值
        //m2：每层的次大值
        int m2 = 0, m1 = 0, cnt = 0;
        for (int j = 1; j <= i; j++) {
            //更新最大值、次大值、最大值坐标
            if (ans[i][j] > m1) {
                m2 = m1;
                m1 = ans[i][j];
                cnt = j;
            }
            //当结果不大于最大值时可能大于次大值
            else if (m2 < ans[i][j]) {
                m2 = ans[i][j];
            }
        }
        //记录每层的最大值坐标和次大值
        mmax[i][0] = cnt;
        mmax[i][1] = m2;
    }
    for (int i = 0; i < m; i++) {
        //（a, b）为被ban点的坐标
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 1 && b == 1) {
            printf("-1\n");
        }
        //若被ban的正好是该行a的最大值点（a，b）,则返回次大值
        else if (mmax[a][0] == b) {
            printf("%d\n", mmax[a][1]);
        }
        //否则返回最大值
        else {
            printf("%d\n", dtu[1][1]);
        }
    }
    return 0;
}
