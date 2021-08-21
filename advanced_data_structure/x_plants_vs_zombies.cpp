/*************************************************************************
	> File Name: plants_vs_zombies.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 04 Feb 2021 09:49:16 PM CST
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 【数据结构C++】 植物大战僵尸
 * 根据速度s不同建立100个大顶堆，同一个堆中的僵尸相对位置相同
 * 每秒选择堆顶元素中最大的一个消灭
 */
#define swap(a, b) { \
    __typeof(a) c = a; \
    a = b, b = c; \
}

#define MAX_N 50000
typedef struct Data {
    //编号、初始位置、速度
    int n, f, s;
} Data;

Data heap[101][MAX_N + 5];

//排序规则
int gt(Data a, Data b) {
    if (a.f - b.f) return a.f > b.f;
    return a.n < b.n;
}

//建堆
void push(Data *h, Data val) {
    h[++h[0].n] = val;
    int ind = h[0].n;
    while (ind / 2 && gt(h[ind], h[ind / 2])) {
        swap(h[ind], h[ind / 2]);
        ind /= 2;
    }
    return ; 
}

//弹出堆顶元素
void pop(Data *h) {
    swap(h[1], h[h[0].n]);
    h[0].n -= 1;
    int ind = 1, temp;
    while (ind * 2 <= h[0].n) {
        temp = ind;
        if (gt(h[ind * 2], h[temp])) temp = ind * 2;
        if (ind * 2 + 1 <= h[0].n && gt(h[ind * 2 + 1], h[temp])) temp = ind * 2 + 1;
        if (temp == ind) break;
        swap(h[temp], h[ind]);
        ind = temp;
    }
    return ;
}

int empty(Data *h) { return h[0].n == 0;  }
Data top(Data *h) { return h[1];  } 
void clear(Data *h) { h[0].n = 0;  }

void init_heap() {
    for (int i = 0; i <= 100; i++) clear(heap[i]);
    return ;
}

void solve() {
    init_heap();
    int n, f, s;
    scanf("%d", &n);
    //把僵尸放入对应的堆中
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &f, &s);
        Data d = {i, f, s};
        push(heap[s], d);
    }
    //每秒在所有堆顶元素中选择一个距离最远的僵尸，打印编号，并弹出
    for (int i = 1; i <= n; i++) {
        int ind = 0, pos = 0;
        for (int j = 1; j <= 100; j++) {
            if (empty(heap[j])) continue;
            int cur_pos = (i - 1) * j + top(heap[j]).f;
            if (ind == 0) {
                ind = j, pos = cur_pos;
                continue;
            }
            if (pos < cur_pos || (pos == cur_pos && top(heap[j]).n < top(heap[ind]).n)) {
                ind = j, pos = cur_pos;
            }
        }
        if (i - 1) printf(" ");
        printf("%d", top(heap[ind]).n);
        pop(heap[ind]);
    }
    printf("\n");
    return ;

}

int main() {
    int tcase, n = 0;
    scanf("%d", &tcase);
    while ((n++) < tcase) {
        printf("Case #%d:\n", n);
        solve();       
    }
    return 0;
}
