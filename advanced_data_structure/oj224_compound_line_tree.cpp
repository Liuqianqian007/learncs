/*************************************************************************
	> File Name: oj224_compound_line_tree.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 05 Feb 2021 12:10:05 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
/* OJ224 复合线段树 
 * 区间操作，需要懒标记
 * 需要两个懒标记：乘法懒标记 加法懒标记
 * 乘法操作时，除乘法懒标记与区间和值外，需要额外修改加法懒标记
 * 加法操作时，只需要修改区间和值与加法懒标记
 */

#define MAX_N 100000
//结点定义：t1乘法懒标记，t2加法懒标记，sum和值
struct Node {
    long long sum, t1, t2;
} tree[(MAX_N << 2) + 5];

long long a[MAX_N + 5];
long long n, m, p;

void mul_tag(long long ind, long long x) {
    tree[ind].sum *= x;
    tree[ind].sum %= p;
    tree[ind].t1 *= x;
    tree[ind].t1 %= p;
    tree[ind].t2 *= x;
    tree[ind].t2 %= p;
    return ;
}

void add_tag(long long ind, long long x, long long n) {
    tree[ind].sum += x * n;
    tree[ind].sum %= p;
    tree[ind].t2 += x;
    tree[ind].t2 %= p;
    return ;
}

//上浮
void UP(long long ind) {
    tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
    tree[ind].sum %= p; 
    return ;
}

//下沉
void DOWN(long long ind, long long l, long long r) {
    if (tree[ind].t1 - 1 || tree[ind].t2) {
        long long a = tree[ind].t1, b = tree[ind].t2;
        long long mid = (l + r) >> 1;
        mul_tag(ind << 1, a);
        mul_tag(ind << 1 | 1, a);
        add_tag(ind << 1, b, mid - l + 1);
        add_tag(ind << 1 | 1, b, r - mid);
        tree[ind].t1 = 1;
        tree[ind].t2 = 0;
    }
    return ;
}

//建立线段树
void build(long long ind, long long l, long long r) {
    tree[ind].t1 = 1; tree[ind].t2 = 0;
    if (l == r) {
        tree[ind].sum = a[l];
        return ;
    }
    long long mid = (l + r) >> 1;
    build(ind << 1, l, mid);
    build(ind << 1 | 1, mid + 1, r);
    UP(ind);
    return ;
}

//区间修改
void modify(long long ind, long long flag, long long x, long long y, long long val, long long l, long long r) {
    if (x <= l && r <= y) {
        if (flag == 0) {
            mul_tag(ind, val);         
        } else {
            add_tag(ind, val, r - l + 1);                    
        }
        return ;         
    }
    long long mid = (l + r) >> 1;
    DOWN(ind, l, r);
    if (x <= mid) modify(ind << 1, flag, x, y, val, l, mid);
    if (y > mid) modify(ind << 1 | 1, flag, x, y, val, mid + 1, r);
    UP(ind);
    return ;
}

//查询区间和值
long long query(long long ind, long long x, long long y, long long l, long long r) {
    if (x <= l && r <= y) {
        return tree[ind].sum;            
    }
    long long mid = (l + r) >> 1;
    long long ans = 0;
    DOWN(ind, l, r);
    if (x <= mid) ans += query(ind << 1, x, y, l, mid);
    ans %= p;
    if (y > mid) ans += query(ind << 1 | 1, x, y, mid + 1, r);
    ans %= p;
    UP(ind);
    return ans;
}

int main() {
        cin >> n >> m >> p;
        for (long long i = 1; i <= n; i++) cin >> a[i];
        build(1, 1, n);
        long long op, x, y, k;
    for (long long i = 0; i < m; i++) {
        cin >> op >> x >> y;
        switch (op) {
            //区间修改：1乘法，2加法 
            case 1: 
            case 2: {
                cin >> k;
                modify(1, op - 1, x, y, k, 1, n);                            
            } break;
            //查询区间和值
            case 3: {
                cout << query(1, x, y, 1, n) << endl;
            } break;                    
        }            
    }
    return 0;
}
