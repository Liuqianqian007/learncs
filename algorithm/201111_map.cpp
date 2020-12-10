/*************************************************************************
	> File Name: 201111_map.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 11 Nov 2020 08:46:13 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

struct node {
    int x, y;
};

int main() {
    map<string, int> m1;
    map<node, int> m2;
    //自定义结构node没有实现哈希函数，会报错
    unordered_map<node, int> m3;
    string a = "123";
    m1["123"] = 999;
    cout << m1[a] << "\t" << m1["123"] << "\t" << m1["666"] << endl;


    return 0;
}
