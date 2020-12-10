/*************************************************************************
	> File Name: 201108_oj508.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 08 Nov 2020 06:55:50 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int n, num[1005], ans;

int main() {
    cin >> n;
    //i从1开始计数
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    sort(num + 1, num + n + 1);
    //当人数大于3人时，每个循环送最慢的两个人过桥
    //当人数小于等于3人时，特判
    for (int i = n ; i > 0; i -= 2) {
        if (i == 1) {
            ans += num[1];
            break;
        } else if (i == 2) {
            ans += num[2];
            break;
        } else if ( i == 3 ) {
            ans += num[3] + num[1] + num[2];
            break;
        } else {
            //送回手电筒最快：最慢最快——最快——次慢最快——最快
            //送过桥单程最快：次快最快——最快——最慢次慢——次快
            //取决于 （次慢+最快）和（次快+次快）谁更小
            ans += min(num[i] + num[1] + num[i - 1] + num[1], num[2] + num[1] + num[i] + num[2]);
        }
    }
    cout << ans << endl;


    return 0;
}
