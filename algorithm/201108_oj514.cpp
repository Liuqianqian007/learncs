/*************************************************************************
	> File Name, 201108_oj514.cpp
	> Author, liuqian
	> Mail, 
	> Created Time, Sun 08 Nov 2020 07,54,25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[15] = {6,2,5,5,4,5,6,3,7,6,2,2};

int sum(int x) {
    if (x == 0) {
        return num[0];
    }
    int ans = 0;
    while (x) {
        ans += num[x % 10];
        x /= 10;
    }
    return ans;
}

int func(int a, int b) {
    int x = sum(a), y = sum(b), z = sum(a + b);
    return x + y + z + 4;
}

int main() {
    int n, ans = 0;
    cin >> n;
    //注意上限
    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            if (func(i, j) == n) {
                ans++;
                cout << i << " + " << j << " = " << i + j << endl;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
