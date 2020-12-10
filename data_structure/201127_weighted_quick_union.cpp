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

//并查集——weighted-quick-uion算法

//结构定义：father[i]是i的代表元素值
//在quick-union算法基础上
//增加size数组，表示元素i所在连通域的大小
typedef struct UnionSet {
    int *father;
    int *size;
    int n;
} UnionSet;

//初始化，代表元素（father）值初始化为元素下标本身
//增加size初始化和赋值
UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * (n + 1));
    u->size = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    return u;
}

//查询操作
int find(UnionSet *u, int x) {
    if (u->father[x] == x) return x;
    return find(u, u->father[x]);
}

//合并操作
//将size大的连通域的根元素作为size小的连通域的根的代表元素
int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] < u->size[fb]) swap(fa, fb);
    u->father[fb] = fa;
    u->size[fa] += u->size[fb];
    return 1;
}

void clear(UnionSet *u) {
    if(u == NULL) return;
    free(u->father);
    free(u->size);
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
