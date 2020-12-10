/*************************************************************************
	> File Name: 201113_oj383.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 13 Nov 2020 06:07:51 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
//oj383-周末舞会

//队列
int main() {
    int x, y, n;
    cin >> x >> y >> n;
    queue<int> qx, qy;
    for (int i = 1; i <= x; i++) {
        qx.push(i);
    }
    for (int i = 1; i <= y; i++) {
        qy.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << qx.front() << " " << qy.front() << endl;
        qx.push(qx.front());
        qy.push(qy.front());
        qx.pop();
        qy.pop();
    }
    return 0;
}
