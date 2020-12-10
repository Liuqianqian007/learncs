/*************************************************************************
	> File Name: euler_11.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 28 Oct 2020 07:41:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//largest product in a grid

//方向数组的使用
//此题题意为八方向，但遍历四个方向而非八方向以防止重复
//右，右下，下，左下
int dirx[4] = {0, 1, 1, 1};
int diry[4] = {1, 1, 0, -1};
int num[30][30], ans;

int main() {
    //从5开始输入，达到外圈补零的效果，省去判断边界
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            cin >> num[i][j];
        }
    }
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            for (int k = 0; k < 4; k++) {
                int t = num[i][j];
                for (int l = 1; l < 4; l++) {
                    int x = i + dirx[k] * l;
                    int y = j + diry[k] * l;
                    t *= num[x][y];
                }
                ans = max(ans, t);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
