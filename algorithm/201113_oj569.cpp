/*************************************************************************
	> File Name: 201113_oj569.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 13 Nov 2020 08:13:50 PM CST
 ************************************************************************/
#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
//oj569-溶液模拟器

//s为盐（溶质）的质量，ws为盐和水（溶液）的质量
struct node {
    double s, ws;
};

int main() {
    //初始的溶液质量、初始浓度和初始溶质的质量
    double ws0, c0, s0;
    scanf("%lf%lf", &ws0, &c0);
    s0 = ws0 * c0 /100;
    int n;
    scanf("%d", &n);
    stack<node> sta;
    for (int i = 0; i < n; i++) {
        //t为操作类型
        char t;
        //这里用scanf会读入之前的\n
        cin >> t;
        //scanf("%c", &t);
        //scanf("%c", &t);
        //加入操作
        if (t == 'P') {
            //当前的溶液质量、当前浓度和当前溶质的质量
            double wst, ct, st;
            scanf("%lf%lf", &wst, &ct);
            st = wst * ct / 100;
            ws0 += wst;
            s0 += st;
            sta.push(node({st, wst}));
        //撤销操作
        } else {
            if (sta.size()) {
                ws0 -= sta.top().ws;
                s0 -= sta.top().s;
                sta.pop();
            }
        }
        printf("%d %.5f\n", (int)ws0, s0 / ws0 * 100);
    }


    return 0;
}
