/*************************************************************************
	> File Name: 201101_oj394.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 01 Nov 2020 08:26:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//二分答案

//ll为起点和终点的距离，n为石头数，m为要移走的岩石数，tl为两块石头的最小距离
int ll, n, m, num[50005], tl;

int func(int d) {
    int cnt = 0, last = 0;
    for (int i = 1; i <= n + 1; i++) {
        //间隔小于d则移除i处的石头，即不更新last，cnt记录移除的石头数
        if (num[i] - last < d) {
            cnt++;
        }
        else {
            last = num[i];
        }
    }
    return cnt;
}

int bin_search() {
    //最小边界为两石头间的最小间隔，最大边界为起点和终点间的距离
    int l = tl, r = ll;
    while(l != r) {
        int mid = (l + r + 1) / 2;
        int s = func(mid);
        if (s <= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

}


int main() {
    cin >> ll >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        if (i == 1) {
            tl = num[1] - num[0];
        } else{
            tl = min(tl, num[i] - num[i - 1]);
        }
    }
    //存入终点
    num[n + 1] = ll;
    cout << bin_search() << endl;
    

    return 0;
}
