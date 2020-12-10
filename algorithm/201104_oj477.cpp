/*************************************************************************
	> File Name: 201104_oj477.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 26 Nov 2020 08:07:23 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;


int main() {
    string str;
    cin >> str;
    int last = -1, ans = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'A' || str[i] == 'E' ||str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            if (last != -1) {
                ans = max(ans, i - last);
            }
            last = i;
        }
    }
    cout << ans << endl;

    return 0;
}
