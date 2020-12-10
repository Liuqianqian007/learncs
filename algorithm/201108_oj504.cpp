/*************************************************************************
	> File Name: 201108_oj504.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 08 Nov 2020 06:12:08 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int n;
string str;

int main() {
    cin >> str >> n;
    //若有前一个数大于后一个数，则删除前面的数
    //否则说明是按从小到大排列的了，那么删除最后一个数
    for (int i = 0; i < n; i++) {
        int ind = str.size() - 1;
        for (int j = 0; j < str.size() - 1; j++) {
            if (str[j] > str[j + 1]) {
                ind = j;
                break;
            }
        }
        str.replace(ind, 1, "");
    }
    //标记第一个非0，然后输出
    int flag = 0;
    for (int i = 0; i < str.size(); i++) {
        if(str[i] != '0') {
            flag = 1;
        }
        if (flag == 1) {
            cout << str[i];
        }
    }
    cout << endl;
    return 0;
}
