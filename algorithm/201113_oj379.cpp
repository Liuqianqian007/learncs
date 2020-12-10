/*************************************************************************
	> File Name: 201113_oj379.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 13 Nov 2020 07:02:13 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
//仓库日志

//货物栈g可以去掉
int main() {
    int n;
    stack<int> g, mmax;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            cin >> t;
            g.push(t);
            if (mmax.empty()) {
                mmax.push(t);
            } else {
                //每次添加货物都入栈一个最大值
                mmax.push(max(t, mmax.top()));
            }
        }else if (t == 1) {
            if (!g.empty()) {
                g.pop();
                mmax.pop();
            }
        }else if (t == 2) {
            if (g.empty()) {
                cout << 0 << endl;
            } else {
                cout << mmax.top() << endl;
            }
        }
    }
    return 0;
}
