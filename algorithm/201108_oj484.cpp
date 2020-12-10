/*************************************************************************
	> File Name: 201108_oj484.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 08 Nov 2020 04:25:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//共有128个ASCII码字符，故数组大小为130
int num[130];
string str;

int main() {
    //输入，并统计每个字符的数目，ctrl+d终止输入
    while (cin >> str) {
        for (int i = 0; str[i]; i++) {
            num[str[i]]++;
        }
    }
    int mmax = 0;
    //统计出现最多的大写字母
    for (int i = 'A'; i <= 'Z'; i++) {
        mmax = max(mmax, num[i]);
    }
    //星号共有mmax行
    for (int i = mmax; i > 0; i--) {
        //字母序最大的出现次数大于等于i次字母end_char的后面不输出空格
        int end_char = 'A';
        for (int j = 'Z'; j > 'A'; j--) {
            if (num[j] >= i) {
                end_char = j;
                break;
            }
        }
        for (int j = 'A'; j <= end_char; j++) {
            if (j != 'A') {
                cout << " ";
            }
            if (num[j] >= i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        if (i != 'A') {
            cout << " ";
        }
        cout << i;
    }
    cout << endl;

    return 0;
}
