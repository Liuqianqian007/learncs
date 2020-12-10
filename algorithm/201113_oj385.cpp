/*************************************************************************
	> File Name: 201113_oj385.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 13 Nov 2020 07:38:54 PM CST
 ************************************************************************/

#include<cstdio>
#include<queue>
using namespace std;
//oj385-海港

//队列存储到港的人的信息

//t表示人到港的时间，c表示人的国籍
struct person {
    int t, c;
};
//n为船只数，con为国家数，mark存放每个国家的人数
int n, con, mark[100005];

int main() {
    queue<person> que;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        //time为当前时刻，pcnt为当前船只的人数
        int time, pcnt;
        scanf("%d%d", &time, &pcnt);
        //当时间间隔大于24h即86400s时，队首出队
        while(!que.empty() && time - que.front().t >= 86400) {
            mark[que.front().c]--;
            if (mark[que.front().c] == 0) {
                con--;
            }
            que.pop();
        }
        //对当前时刻到港的船上的每个人执行操作：统计国籍，且如有新增国家则更新国家数
        for (int j = 0; j < pcnt; j++) {
            int country;
            scanf("%d", &country);
            que.push(person({time, country}));
            mark[country]++;
            if (mark[country] == 1) {
                con++;
            }
        }
        printf("%d\n", con);
    }
    return 0;
}
