/*************************************************************************
	> File Name: 201120_oj528.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 20 Nov 2020 06:49:18 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
//关系网络
//求最少关系人——广搜
//题目所给矩阵为邻接表
//状态转移：遍历邻接矩阵的一行

//check标记此人是否成为过中间人
int n, x, y, check[105], arr[105][105];

//now为当前人的编号
struct node {
    int now, step;
};

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    queue<node> que;
    que.push((node){x, 0});
    check[x] = 1;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        //遍历邻接表的当前行，即将当前人所有认识的人加入队列
        for (int i = 1; i <= n; i++) {
            if (arr[temp.now][i] == 1 && check[i] == 0) {
                //如果是要认识的人，不需要加一，因为要求的是中间人
                if (i == y) {
                    cout << temp.step << endl;
                    return 0;
                }
                //中间人加1，并标记
                que.push((node){i, temp.step + 1});
                check[i] = 1;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
