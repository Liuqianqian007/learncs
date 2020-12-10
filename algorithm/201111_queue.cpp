/*************************************************************************
	> File Name: 201111_queue.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 11 Nov 2020 07:15:12 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> que;
    for (int i = 9; i > 4; i--) {
        que.push(i);
    }
    while (!que.empty()) {
        cout << "que.front() = " << que.front() << "\tque.size() = " << que.size() << endl;
        que.pop();
    }


    return 0;
}
