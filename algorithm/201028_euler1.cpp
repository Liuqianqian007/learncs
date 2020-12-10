/*************************************************************************
	> File Name: 201028_1.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 28 Oct 2020 06:22:37 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//3和5的倍数和-multiple of 3 and 5
int main() {
    /*
    int ans = 0;
    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            ans += i;
        }
    }
    cout << ans << endl;
    */
    int t3 = (3 + 999) * 333 / 2;
    int t5 = (5 + 995) * 199 / 2;
    int t15 = (15 + 990) * 66 / 2;
    cout << t3 + t5 - t15 << endl;
    return 0;
}
