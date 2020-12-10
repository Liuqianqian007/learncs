/*************************************************************************
	> File Name: 201031_header1.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 31 Oct 2020 06:15:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void funcB(int n ) {
    if (n == 0) return;
    printf("funcB : %d\n", n);
    funcA(n - 1);
    return;
}

void funcA(int n ) {
    if (n == 0) return;
    printf("funcA : %d\n", n);
    funcB(n - 1);
    return;
}


