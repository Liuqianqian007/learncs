/*************************************************************************
	> File Name: 201115_oj235.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 17 Nov 2020 10:07:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//递归实现指数型枚举

//n表示从1~n中选择
//num记录输出的数列
int n, num[15], index;

void P() {
    for (int i = 0; i <= index; i++) {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;
}
//参数x表示这轮从几开始选
//index表示当前在选第几个数，从上一次递归回溯后，要减1
void func(int x) {
    for (int i = x; i <= n; i++) {
        num[index] = i;
        P();
        index++;
        func(i + 1);
        index--;
    }
}

int main() {
    cin >> n;
    func(1);
    return 0;
}
