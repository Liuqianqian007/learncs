/*************************************************************************
	> File Name: oj329_weakened_integer_problem.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sun 24 Jan 2021 09:37:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ329 弱化的整数问题 树状数组
 * 区间修改，需要将原数组转化为差分数组
 * 查询原数组元素即为求差分数组的前缀和，前缀和由树状数组表示
 * 在差分数组上建立树状数组
 */

#define MAX_N 100000
//c是建立在差分数组之上的树状数组
int c[MAX_N + 5];
#define lowbit(x) (x & -x)

//树状数组单点修改：修改差分数组的树状数组，i是修改的位置，x是修改的差值，n是数组长度
void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return;
}

//树状数组查询：得到差分数组基于树状数组的前缀和，即得到原数组的元素值
int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    //m是操作次数，n是原数组长度，now是当前输入的值，pre是前一个输入的值
    int m, n, now, pre = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> now;
        add(i, now - pre, n);
        pre = now;
    }
    cin >> m;
    char s[10];
    int l, r, x;
    for (int i = 0; i < m; i++) {
        cin >> s;
        switch (s[0]) {
            //原数组区间修改，区间(l, r)内所有元素都加上x
            case 'C':{
                cin >> l >> r >> x;
                add(l, x, n);
                add(r + 1, -x, n);
                break;
            }
            //查询原数组的值
            case 'Q': {
                cin >> x;
                cout << query(x) << endl;;
                break;
            }
        }
    }
    return 0;
}
