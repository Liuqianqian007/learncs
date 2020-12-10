/*************************************************************************
	> File Name: 201108_oj516.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 08 Nov 2020 08:18:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//num[i]存放到第i个位置为止有多少个C
int n, num[100005], wcnt;
long long ans;
char str[100005];

int main() {
    //str[0]和num[0]都初始化为0，方便计算
    cin >> n >> &str[1];//string类型不可以这么写

    for (int i = 1; i <= n; i++) {
        if (str[i] == 'C') {
            num[i] = num[i - 1] + 1;
        } else {
            num[i] = num[i - 1];
        }
    }
    for (int i = n; i > 0; i--) {
        //从后往前W的计数
        if (str[i] == 'W') {
            wcnt++;
        }
        if (str[i] == 'O') {
            ans += (long long )wcnt * num[i - 1];
        }
    }
    cout << ans << endl;

    return 0;
}
