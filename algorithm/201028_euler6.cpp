/*************************************************************************
	> File Name: euler_6.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 28 Oct 2020 06:55:53 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//和平方减平方和-sum square difference
int main() {
    int sum = 0, psum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
        psum += i * i;
    }
    cout << sum * sum  - psum << endl;
    return 0;
}
