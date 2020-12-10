/*************************************************************************
	> File Name: 201030_18.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 30 Oct 2020 07:30:27 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//最大路径和/maximum path sum 1

//将所给三角形视为直角三角形更直观

//num为原数据，ans为走到每一点的最大路径
int n, num[20][20], ans[20][20];

int main() {
    //共15行
    n = 15;
    //读入数据，外圈补零
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    
    //方法一：从上往下走
    /*
    int fin = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = max(ans[i - 1][j - 1], ans[i - 1][j]) + num[i][j];
            fin = max(fin, ans[i][j]);
        }
    }
    cout << fin << endl;
    */
    
    //方法二：从下往上走    
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = max(ans[i + 1][j], ans[i + 1][j + 1]) + num[i][j];
        }
    }
    cout << ans[1][1] << endl;

    return 0;
}
