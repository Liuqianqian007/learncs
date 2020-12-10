/*************************************************************************
	> File Name: 201030_large_multiple.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 30 Oct 2020 06:29:21 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
//大数乘法

int main() {
    char s1[1005], s2[1005];
    int n1[1005] = {0}, n2[1005] = {0}, ans[1005] = {0};
    cin >> s1 >> s2;
    n1[0] = strlen(s1), n2[0] = strlen(s2);
    //积的位数为乘数位数之和减1
    ans[0] = n1[0] + n2[0] - 1;

    //乘数从字符串转化乘数字数组
    for (int i = 1, j = n1[0] - 1; i <= n1[0]; i++, j--){
        n1[i] = s1[j] - '0';
    }
    for (int i = 1, j = n2[0] - 1; i <= n2[0]; i++, j--) {
        n2[i] = s2[j] - '0';
    }
    //乘法运算（重点）
    for (int i = 1; i <= n1[0]; i++) {
        for (int j = 1; j <= n2[0]; j++) {
            ans[i + j - 1] += n1[i] * n2[j];
        }
    }
    for (int i = 1; i <= ans[0]; i++) {
        //处理进位
        if (ans[i] > 9) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            if (i == ans[0]) {
                ans[0]++;
            }
        }
    }
     for (int i = ans[0]; i > 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
