/*************************************************************************
	> File Name: 201113_oj376.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 13 Nov 2020 06:39:32 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
//oj376-机器翻译

//队列

int ans, n, m, mark[1005];
int main() {
    cin >> m >> n;
    queue<int> que;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (mark[t] == 0) {
            ans++;
            if (que.size() == m) {
                mark[que.front()] = 0;
                que.pop();
            }
            que.push(t);
            mark[t] =1;
        }
    }
    cout << ans << endl;
    return 0;
}
