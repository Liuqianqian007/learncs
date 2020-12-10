/*************************************************************************
	> File Name: euler_13.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 28 Oct 2020 08:42:36 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

//大和-大整数相加-large sum

int num1[105], num2[105], sum[105];
char s1[105], s2[105];


int main() {
    cin >> s1 >> s2;
    //数组第一位记录数字位数
    num1[0] = strlen(s1);
    num2[0] = strlen(s2);
    //字符串转化为数字数组：低位在前
    for (int i = 0, j = num1[0]; i < num1[0]; i++, j--) {
        num1[j] = s1[i] - '0';
    }
    for (int i = 0, j = num2[0]; i < num2[0]; i++, j--) {
        num2[j] = s2[i] - '0';
    }
    sum[0] = max(num1[0], num2[0]);
    //数字数组相加
    for (int i = 1; i <= sum[0]; i++) {
        sum[i] = num1[i] + num2[i];
    }
    for (int i = 1; i <= sum[0]; i++) {
        //进位
        if (sum[i] > 9) {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
            //最高位需要进位则更新和的位数
            if (i == sum[0]) {
                sum[0]++;
            }
        }
    }
    //反向输出
    for (int i = sum[0]; i> 0; i--) {
        cout << sum[i];
    }
    cout << endl;
    return 0;
}
