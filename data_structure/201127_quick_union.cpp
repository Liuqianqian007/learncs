/*************************************************************************
	> File Name: 201127_quick_find.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 27 Nov 2020 08:33:19 PM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
//并查集——quick-union算法
//OJ71 朋友圈

//结构定义：father[i]是i的代表元素值
typedef struct UnionSet {
    int *father;
    int n;
} UnionSet;

//初始化，father值初始化为元素下标本身
UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
    }
    return u;
}

//查询操作，传入元素下标，返回其代表元素的根部元素
int find(UnionSet *u, int x) {
    if (u->father[x] == x) return x;
    return find(u, u->father[x]);
}

//合并操作
//若a，b的代表元素的根不相等
//则将a的代表元素的根的代表元素更新为b的代表元素
int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    u->father[fa] = fb;
    return 1;
}

void clear(UnionSet *u) {
    if(u == NULL) return;
    free(u->father);
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
