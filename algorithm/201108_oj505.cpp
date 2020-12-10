/*************************************************************************
	> File Name: 201108_oj505.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 08 Nov 2020 06:34:59 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s[100005];
int n;

//保证连接后的字符串按字典序最大排列
bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << endl;

    return 0;
}
