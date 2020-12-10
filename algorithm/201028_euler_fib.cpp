/*************************************************************************
    > File Name: euler_fib.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 28 Oct 2020 08:06:51 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//递归+记忆化（记忆数组）~= 递推
//递归效率比递推慢

long long num[50];

int f(int n) {
    if (n == 1 || n == 2) return 1;
    if (num[n]) return num[n];
    return num[n] = f(n - 1) + f(n - 2);
}

int main() {
    for (int i = 1; i <= 30; i++) {
        cout << i << " : " << f(i) << endl;
        
    }
    
    return 0;
}
