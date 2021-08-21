/*************************************************************************
	> File Name: oj333_maximum_interval_subsegment_sum.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 27 Jan 2021 07:33:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ333 区间最大子段和 线段树(单点修改+区间查询)
 * 每个结点维护区间最大子段和imax、左起最大子段lmax和右起最大子段rmax和3个字段
 * 线段树进行区间查询时，各个子结点是从左往右依次合并的
 */
#define MAX_N 500000
#define L(ind) (ind << 1)
#define R(ind) (ind << 1 | 1)
#define SUM(ind) tree[ind].sum
#define INMAX(ind) tree[ind].imax
#define LMAX(ind) tree[ind].lmax
#define RMAX(ind) tree[ind].rmax

//定义线段树结构，大小为4n
struct Data {
    int sum, imax, lmax, rmax;
} _tree[(MAX_N << 2) + 5];

//数组tree的起始坐标是-1
Data *tree = _tree + 1;

int n, m, flag;
int val[MAX_N + 5];

//线段树向上更新：更新结点中的三个字段imax、lmax、rmax 
//sumb表示该结点区间中所有元素的和
void UP(int father, int lchild, int rchild) {
    SUM(father) = SUM(lchild) + SUM(rchild);
    LMAX(father) = max(LMAX(lchild), SUM(lchild) + LMAX(rchild));
    RMAX(father) = max(RMAX(rchild), SUM(rchild) + RMAX(lchild));
    INMAX(father) = max(max(INMAX(lchild), INMAX(rchild)), RMAX(lchild) + LMAX(rchild));
    return;
}

//建立线段树
void build(int ind, int l, int r) {
    if (l == r) {
        SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = val[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(L(ind), l, mid);
    build(R(ind), mid + 1, r);
    UP(ind, L(ind), R(ind));
    return;
}

//修改i位置的值为x，ind为线段树起始坐标，（l，r）是线段树区间
void modify(int ind, int l, int r, int i, int x) {
    if (l == r) {
        SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = x;
        return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) {
        modify(L(ind), l, mid, i, x);
    }
    else {
        modify(R(ind), mid + 1, r, i, x);
    }
    UP(ind, L(ind), R(ind));
    return;
}

//查询线段树区间（x，y）的最大子段和，保存在tree[0]中
//线段树进行区间查询时，各个子结点是从左往右依次合并的
void query(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        if (flag) {
            tree[0] = tree[ind];
            flag = 0;
        }
        else {
            //将已合并的区间结果放在tree[0]中，然后将tree[0]和当前区间合并到tree[-1]中
            UP(-1, 0, ind);
            tree[0] = tree[-1];
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        query(L(ind), l, mid, x, y);
    }
    if (y > mid) {
        query(R(ind), mid + 1, r, x, y);
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", val + i);
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        switch (k) {
            //查询
            case 1:{
                if (x > y) swap(x, y);
                flag = 1;
                query(1, 1, n, x, y);
                printf("%d\n", INMAX(0));
                break;
            }
            //修改
            case 2: {
                modify(1, 1, n, x, y);
                break;
            }
        }
    }
    return 0;
}
