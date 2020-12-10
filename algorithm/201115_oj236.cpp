/*************************************************************************
	> File Name: 201115_oj236.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 17 Nov 2020 10:38:58 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//递归实现组合型枚举

//index表示数列的元素下标
int n, m, num[15], index;

void P() {
    for (int i = 0; i < m; i++) {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;
}

//s表示当前这轮可选的最小的数
//left表示还剩几个数要选
void func(int s, int left) {
    if (left == 0) {
        P();
        return;
    }
    for (int i = s; i <= n; i++) {
        num[index] = i;
        index++;
        func(i + 1, left - 1);
        index--;
    }
}

int main() {
    cin >> n >> m;
    func(1, m);


    return 0;
}
