/*************************************************************************
	> File Name: nth_element.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 02 Mar 2021 01:38:36 PM CST
 ************************************************************************/

//nth_element示例
#include <iostream>     
#include <algorithm>    
#include <vector>       
using namespace std;

bool myfunction (int i,int j) { return (i<j);  }

int main () {
    vector<int> myvector;

    for (int i=1; i<10; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
    random_shuffle (myvector.begin(), myvector.end());

    //使用默认的<运算符排序
    nth_element (myvector.begin(), myvector.begin()+5, myvector.end());

    //使用比较函数myfunction排序
    nth_element (myvector.begin(), myvector.begin()+5, myvector.end(),myfunction);

    //输出结果
    cout << "myvector contains:";
    for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    return 0;
}
