/*************************************************************************
	> File Name: 201030_25.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 30 Oct 2020 06:09:47 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//一千位的斐波那契数/1000-digit Fibonaci number

//大整数加法
//大数n1加到小数n2上面
int func(int *n1, int *n2) {
    n2[0] = n1[0];
    for (int i = 1; i <= n2[0]; i++) {
        n2[i] += n1[i];
        if (n2[i] > 9) {
            n2[i + 1] += n2[i] / 10;
            n2[i] %= 10;
            if (i == n2[0]) {
                n2[0]++;
            }
        }
    }
    return n2[0] >= 1000;
}

//递推:循环加
int main() {
    //num存储两个大整数
    //未初始化的自动赋值为0 
    //num[i][0]为大整数的位数
    int num[2][1100] = {{1, 1}, {1, 1}};

    //两个数来回倒，未满足条件则将两个数交换
    int a = 0, b = 1;
    for (int i = 3; 1; i++) {
        if (func(num[a], num[b]) == 1) {
            cout << i << endl;
            break;
        }
        swap(a, b);
    }
    return 0;
}
