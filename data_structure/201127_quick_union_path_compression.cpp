/*************************************************************************
	> File Name: 201127_quick_find.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 27 Nov 2020 08:33:19 PM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

#define swap(a, b) {\
    __typeof (a) __temp = a;\
    a = b; b = __temp;\
}
//并查集——quick-union算法+路径压缩
//注释掉的部分是weighted优化，去掉后性能相差不大

//结构定义
typedef struct UnionSet {
    int *father;
    //int *size;
    int n;
} UnionSet;

//初始化
UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * (n + 1));
    //u->size = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
        //u->size[i] = 1;
    }
    return u;
}

//查询
//将x所在连通域的father直接作为x的father
int find(UnionSet *u, int x) {
    return u->father[x] = (u->father[x] == x ? x : find(u, u->father[x]));
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    //if (u->size[fa] < u->size[fb]) swap(fa, fb);
    u->father[fb] = fa;
    //u->size[fa] += u->size[fb];
    return 1;
}

void clear(UnionSet *u) {
    if(u == NULL) return;
    free(u->father);
    //free(u->size);
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
