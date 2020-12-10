/*************************************************************************
	> File Name: 201115_oj237.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 17 Nov 2020 11:03:19 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[15], mark[15], index;

void P() {
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;
}

//left表示还剩几个数要排列
void func(int left) {
    if (left == 0) {
        P();
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            num[index] = i;
            index++;
            func(left - 1);
            index--;
            //从上一层递归回溯后要将mark过的数字回归
            mark[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    func(n);
    return 0;
}
