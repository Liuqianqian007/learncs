/*************************************************************************
	> File Name: operator1.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 15 Oct 2020 11:50:24 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int a = 7, b = 3, c;
    a += 7;
    int *p = &a;
    (*p)--;
    printf("a = %d, b = %d\n", a, b);
    /*
    int temp = a;
    a = b;
    b = temp;
    */
    
    //等价于交换，异或^为自己的逆运算
    a ^= b;
    b ^= a;
    a ^= b;
    printf("swap : a = %d, b = %d\n", a, b);
    return 0;
}
