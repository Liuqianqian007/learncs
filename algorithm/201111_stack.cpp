/*************************************************************************
	> File Name: 201111_stack.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 11 Nov 2020 07:21:41 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<int> sta;
    for(int i = 9; i > 4; i--) {
        sta.push(i);
    }
    while(!sta.empty()){
        cout << "sta.top() = " << sta.top() << "\tsta.size() = " << sta.size() << endl;
        sta.pop();
    } 

    return 0;
}
