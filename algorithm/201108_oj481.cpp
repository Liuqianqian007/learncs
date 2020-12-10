/*************************************************************************
	> File Name: 201108_oj481.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 08 Nov 2020 03:50:28 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
//冰壶比赛
//模拟问题

int r, ans[15][2];

void p(int n) {
    int a1 = 0, a2 = 0;
    for (int i = 1; i < n; i++) {
        a1 += ans[i][0];
        a2 += ans[i][1];
        cout << ans[i][0] << ":" << ans[i][1] << endl;
    }
    cout << a1 << ":" << a2 << endl;
}

int main() {
    cin >>r;
    //输入数据
    for (int i = 1; i <= 10; i++) {
        int num1[10] = {0}, num2[10] = {0};
        for (int j = 0; j < 8; j++) {
            cin >> num1[j];
            //一方弃权，提前输出
            if (num1[j] == -1) {
                p(i);
                return 0;
            }
        }
        for (int j = 0; j < 8; j++ ) {
            cin >> num2[j];
        }
        //排序
        sort(num1, num1 + 8);
        sort(num2, num2 + 8);
        //统计比分
        if (num1[0] < num2[0]) {
            for (int j = 0; j < 8; j++) {
                if (num1[j] >r ||num1[j] >= num2[0]) break;
                ans[i][0]++;
            }
        }else {
            for (int j = 0; j < 8; j++) {
                if (num2[j] > r || num2[j] >= num1[0]) break;
                ans[i][1]++;
            }
        }
    }
    //输出结果
    p(11);
    return 0;
}
