/*************************************************************************
	> File Name: 201101_oj380.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 03 Nov 2020 04:46:32 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//大统领投票

//需要用到编号，把编号和票数放在一个结构体中
struct Node {
    int index;
    string data;
};

Node arr[105];

bool cmp(Node a, Node b) {
    if (a.data.size() == b.data.size()) return a.data > b.data; 
    return a.data.size() > b.data.size();
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].data;
        arr[i].index = i + 1;
    }
    sort(arr, arr + n, cmp);
    cout << arr[0].index << endl << arr[0].data << endl;
    return 0;
}
