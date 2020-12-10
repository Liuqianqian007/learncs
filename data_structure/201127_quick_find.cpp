/*************************************************************************
	> File Name: 201127_quick_find.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 27 Nov 2020 08:33:19 PM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
//并查集——quick-find算法
//OJ71 朋友圈

//结构定义
typedef struct UnionSet {
    int *color;
    int n;
} UnionSet;

//初始化并查集，color初始值等于下标值1~n
UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    //从1开始存
    u->color = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->color[i] = i;
    }
    return u;
}

//查询操作：传入元素下标，返回其颜色值
int find(UnionSet *u, int x) {
    return u->color[x];
}

//合并操作：传入两个元素下标a，b
int merge(UnionSet *u, int a, int b) {
    if (find(u, a) == find(u, b)) return 0;
    //将所有与元素a颜色相同的元素的颜色改成b的颜色
    int color_a = u->color[a];
    for (int i = 1; i <= u->n; i++) {
        if (u->color[i] != color_a) continue;
        u->color[i] = u->color[b];
    }
    return 1;
}

//销毁
void clear(UnionSet *u) {
    if(u == NULL) return;
    free(u->color);
    free(u);
    return;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: merge(u, b, c);break;
            case 2: printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No");
        }
    }
    clear(u);
    return 0;
}
