/*************************************************************************
	> File Name: oj223_segment_tree_template2.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Mon 25 Jan 2021 10:44:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
/* OJ223 线段树模板（二）
 * 区间修改和区间查询（和值）
 */

#define MAX_N 10000

//线段树结构定义：tag为懒标记，用于区间修改
struct {
    long long  sum, tag;
} tree[MAX_N << 2];
//arr存储题目所给序列
int arr[MAX_N + 5];

//向上更新，仅更新和值，不更新懒标记tag
void update(int ind) {
    tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
    return;
}

//下沉标记：若懒标记不为0，则同时更新左右孩子的值和懒标记
void down(int ind, int l, int r) {
    if (tree[ind].tag) {
        long long val = tree[ind].tag;
        int mid = (l + r) >> 1;
        tree[ind << 1].sum += val * (mid - l + 1);
        tree[ind << 1].tag += val;
        tree[ind << 1 | 1].sum += val * (r - mid);
        tree[ind << 1 | 1].tag += val;
        //清空当前结点的懒标记
        tree[ind].tag = 0;
    }
    return;
}

//线段树建立
void build_tree(int ind, int l, int r) {
    if (l == r) {
        tree[ind].sum = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(ind << 1, l, mid);
    build_tree(ind << 1 | 1, mid + 1, r);
    update(ind);
    return;
}

//区间修改 
void modify(int ind, int l, int r, int x, int y, long long val) {
    if (x <= l && r <= y) {
        tree[ind].sum += val * (r - l + 1);
        tree[ind].tag += val;
        return;
    }
    //递归前向下标记
    down(ind, l, r);
    int mid = (l + r) >> 1;
    //修改左子树
    if (mid >= x) {
        modify(ind << 1, l, mid, x, y, val);
    }
    //修改右子树，不能是else
    if (mid < y) {
        modify(ind << 1 | 1, mid + 1, r, x, y, val);
    }
    //递归后向上更新
    update(ind);
    return;
}

//区间查询（和值）
long long query(int ind, int l, int r, int x, int y) {
    if (x <= l && y >= r) {
        return tree[ind].sum;
    }
    //递归前向下标记
    down(ind, l, r);
    int mid = (l + r) >> 1;
    long long  ans = 0;
    //查询左子树，累加
    if (mid >= x) {
        ans += query(ind << 1, l, mid, x, y);
    }
    //查询右子树，累加
    if (mid < y) {
        ans += query(ind << 1 | 1, mid + 1, r, x, y);
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    build_tree(1, 1, n);

    int a, b, c, d;
    for (int i = 0; i < m; i++ ) {
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: {
                scanf("%d", &d);
                modify(1, 1, n, b, c, d);
                break;
            }
            case 2: {
                if (b > c) {
                    printf("0\n");
                    break;
                }
                printf("%lld\n", query(1, 1, n, b, c));
                break;
            }
        }
    }
    return 0;
}
