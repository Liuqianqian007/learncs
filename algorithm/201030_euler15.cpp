/*************************************************************************
	> File Name: 201030_15.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 30 Oct 2020 06:52:31 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//网格路径/lattice paths

//方法一：动态规划,即递推(也可用递归+记忆化)
int main() {
    //注意：20个网格有21行
    //外圈补零，方便处理
    long long  dp[25][25] = {0};
    for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= 21; j++) {
            if(i ==1 && j == 1) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            
        }
    }  
    cout << dp[21][21] << endl;

    //方法二：从40步中任意选择20向右，即求组合C(40 20)
    //一边乘一边除以防越界
    //从大乘到小、从小除到大以防除不尽
    /*
    long long ans = 1;
    for (int i = 40, j = 1; i > 20; i--, j++) {
        ans *= i;
        ans /= j;
    }
    cout << ans << endl;
    */
    return 0;
}
