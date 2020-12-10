/*************************************************************************
	> File Name: 201113_oj378.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 13 Nov 2020 06:14:52 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
//字符串括号匹配2

//栈
//非括号字符不用处理

int main() {
    string s;
    cin >> s;
    stack<char> sta;
    for (int i = 0; i < s.size(); i++) {
        //遇到左括号则入栈
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            sta.push(s[i]);
        } else if (s[i] == ')'){
            //要考虑栈为空即没有左括号的情况
            if (sta.empty() || sta.top() != '(') {
                cout << "NO" << endl;
                return 0;
            }
            sta.pop();
        } else if (s[i] == ']') {
            if (sta.empty() || sta.top() != '[') {
                cout << "NO" << endl;
                return 0;
            }
            sta.pop();
        } else if (s[i] == '}') {
            if (sta.empty() || sta.top() != '{') {
                cout << "NO" << endl;
                return 0;
            }
            sta.pop();
        }
    }
    //要考虑栈不为空，即只有左括号没有右括号的情况
    if (sta.empty()) {
        cout << "YES" << endl;         
    } else {
        cout << "NO" << endl;
    }


    return 0;
}
