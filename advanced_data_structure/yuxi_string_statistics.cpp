/*************************************************************************
	> File Name: string_statistics.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Mon 01 Feb 2021 12:25:58 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* 预习课 字符串统计-AC自动机 */
#define MAX_N 20000
#define BASE 26

struct Node {
    //cnt指向第i个单词的计数的地址，即&ans[i]
    int flag, *cnt;
    int next[BASE], fail;
} tree[MAX_N + 5];


int n;
char str[100005];
int *ans[MAX_N + 5];

int que[MAX_N + 5], head, tail;
int root = 1, cnt = 2;
//新增结点：结点存储在队列数组que中，新增结点即为将当前下标+1
int getNewNode() {
    return cnt++;
}

//生成字典树：将单词str插入字典树中
int * insert(const char *str) {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNewNode();
        p = tree[p].next[ind];
    }
    tree[p].flag = 1;
    //成词结点处用cnt记录该单词的计数
    if (tree[p].cnt == NULL) {
        tree[p].cnt = (int *)malloc(sizeof(int));
        tree[p].cnt[0] = 0;
    }
    return tree[p].cnt;
}

void build_ac() {
    head = tail = 0;
    //0代表空结点
    tree[root].fail = 0;
    for (int i = 0; i < BASE; i++) {
        //根结点下一层结点的等价匹配结点是根结点
        if (tree[root].next[i] == 0) {
            tree[root].next[i] = root;
            continue;
        }
        //根结点处的路径压缩
        tree[tree[root].next[i]].fail = root;
        //将根结点下一层结点加入队列que
        que[tail++] = tree[root].next[i];
    }
    while (head < tail) {
        int p = que[head++];
        for (int i = 0; i < BASE; i++) {
            int c = tree[p].next[i], k = tree[p].fail;
            if (c == 0) {
                tree[p].next[i] = tree[k].next[i];
                continue;
            }
            k = tree[k].next[i];
            tree[c].fail = k;
            que[tail++] = c;
        }
    }
    return;
}

void match(const char *str) {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] -'a', q;
        p = tree[p].next[ind];
        q = p;
        while (q) {
            if (tree[q].flag) {
                (*tree[q].cnt) += 1;
            }
            q = tree[q].fail;
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        ans[i] = insert(str);
    }
    scanf("%s", str);
    build_ac();
    match(str);
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, *ans[i]);
    }
    return 0;
}
