/*************************************************************************
	> File Name: segment_tree.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 26 Dec 2020 07:28:02 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdint>
using namespace std;
/* OJ222 线段树模板（一）
 *单点修改和区间查询（最大值）
 */

#define MAX_N 10000

//线段树的结构定义，大小为4n
struct {
    int max_num;
    int l, r;
} tree[MAX_N << 2];

//arr存储输入的序列
int arr[MAX_N + 5];

//更新线段树的当前结点
void update(int ind) {
    tree[ind].max_num = max(tree[ind << 1].max_num, tree[ind << 1 | 1].max_num);
    return;
}

//线段树建立
void build_tree(int ind, int l, int r) {
    tree[ind].l = l, tree[ind].r = r;
    //当前为叶子结点时，最大值即序列的元素值
    if (l == r) {
        tree[ind].max_num = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    //分别建立左子树和右子树
    build_tree(ind * 2, l, mid);
    build_tree(ind * 2 + 1, mid + 1, r);
    //更新当前结点
    update(ind);
}

//单点修改：ind为线段树的起始位置，k为序列中要修改的元素坐标，val为修改后的值
void modify(int ind, int k, int val) {
    //找到了要修改的元素在线段树中的位置
    if (tree[ind].l == tree[ind].r) {
        tree[ind].max_num = val;
        return;
    }
    int mid = (tree[ind].l + tree[ind].r) >> 1;
    if (k <= mid) {
        modify(ind << 1, k, val);
    }
    else {
        modify(ind << 1 | 1, k, val);
    }
    //更新当前值
    update(ind);
    return;
}


//区间查询：ind为线段树起始位置， x和y为待查询的区间端点
int query(int ind, int x, int y) {
    if (tree[ind].l >= x && tree[ind].r <= y) {
        return tree[ind].max_num;
    }
    int ans = INT32_MIN;
    int mid = (tree[ind].l + tree[ind].r) >> 1;
    if (mid >= x) {
        ans = max(ans, query(ind << 1, x, y));
    }
    if (mid < y) {
        ans = max(ans, query(ind << 1 | 1, x, y));
    }
    return ans;
}

int main() {
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    //读入数据
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    build_tree(1, 1, n);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: modify(1, b, c);break;
            case 2: {
                if (b > c) {

                    printf("-2147483648\n");
                    break;
                }
                printf("%d\n", query(1, b, c));
            }break;
        }
    }
}
