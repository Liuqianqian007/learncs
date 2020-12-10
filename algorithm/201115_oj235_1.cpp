/*************************************************************************
	> File Name: 201115_oj235.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 17 Nov 2020 10:07:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//递归实现指数型枚举
//方法二

//n表示从1~n中选择
//num记录输出的数列
int n, num[15];

void P(int deep) {
    for (int i = 1; i <= deep; i++) {
        if (i != 1) cout << " ";
        cout << num[i];
    }
    cout << endl;
}
//参数x表示这轮从几开始选
//参数deep表示当前在选第几个数
void func(int x, int deep) {
    for (int i = x; i <= n; i++) {
        num[deep] = i;
        P(deep);
        func(i + 1, deep + 1);
    }
}

int main() {
    cin >> n;
    func(1, 1);
    return 0;
}
