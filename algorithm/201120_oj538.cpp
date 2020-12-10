/*************************************************************************
	> File Name: 201120_oj538.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 20 Nov 2020 07:20:31 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//图的遍历
//深搜

//arr是题目所给邻接图，check为去重数组（一维）
int n, arr[25][25], check[25];

//递归深搜
void func(int now) {
    if (now != 1) {
        cout << "-";
    }
    cout << now;
    check[now] = 1;
    for (int i = 1; i <= n; i++) {
        //该元素邻接且没被标记过，继续深搜
        if (arr[now][i] == 1 && check[i] == 0) {
            func(i);
        }
    }
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    //遍历从没被标记过的点，进行深搜
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            func(i);
        }
    }
    cout << endl;

    return 0;
}
