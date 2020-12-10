/*************************************************************************
	> File Name: 201108_oj485.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 08 Nov 2020 04:39:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//均分纸牌
int n, num[105], ans, sum, avg;

int main() {
    cin >>n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum += num[i];
    }
    avg = sum / n;
    for (int i = 0; i < n - 1; i++) {
        if (num[i] != avg) {
            ans++;
            num[i + 1] += num[i] - avg;
            //可以去掉
            num[i] = avg;
        }
    }
    cout << ans << endl;

    return 0;
}
