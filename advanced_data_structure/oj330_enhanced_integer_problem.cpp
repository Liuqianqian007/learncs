/*************************************************************************
	> File Name: oj330_enhanced_integer_problem.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Mon 25 Jan 2021 02:45:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ330 加强的整数问题
 * 公式推导
 * 查询：维护两个差分数组的树状数组（前缀和）
 */

#define MAX_N 100000
#define lowbit(x) (x & -x)
long long c[2][MAX_N + 5];

//树状数组单点修改
//k代表第k个树状数组，i表示修改的位置，x表示差值，n是数组大小
void add(int k, int i, long long x, int n) {
    while (i <= n) {
        c[k][i] += x;
        i += lowbit(i);
    }
    return;
}

//树状数组查询前缀和
//k代表第k个树状数组，i表示到i位置为止的前缀和
long long query(int k, int i) {
    long long sum = 0;
    while(i) {
        sum += c[k][i];
        i -= lowbit(i);
    }
    return sum;
}

//原数组到i位置为止的前缀和
long long S(int i) {
    return (i + 1) * query(0, i) - query(1, i);
}

//单点修改公式中的两个差分数组的树状数组
void modify(int i, long long x, int n) {
    add(0, i, x, n);
    add(1, i, i * x, n);
    return;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int pre = 0, now;
    //读入序列，建立两个差分数组
    for (int i = 1; i <= n; i++) {
        scanf("%d", &now);
        modify(i, now - pre, n);
        pre = now;
    }
    int l, r, d;
    char s[10];
    for (int i = 0; i < m; i++) {
        scanf("%s", s);
        switch (s[0]) {
            //原数组的区间修改
            case 'C':{
                scanf("%d%d%d", &l, &r, &d);
                modify(l, d, n);
                modify(r + 1, -d, n);
                break;
            }
            //原数组的区间和查询
            case 'Q': {
                scanf("%d%d", &l, &r);
                printf("%lld\n", S(r) - S(l - 1));
                break;
            }
        }
    }
    return 0;
}
