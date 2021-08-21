/*************************************************************************
	> File Name: character_rotation_matrix.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 04 Feb 2021 10:38:07 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

/* 【数据结构C++】 字符旋转矩阵 
 * 步骤：
 * 1. 还原原字符串。
 * 2. 用AC自动机进行匹配
 */
#define MAX_N 110000
char t[MAX_N + 5], s[MAX_N + 5];
int ind[MAX_N + 5], *ans[MAX_N + 5];

bool cmp(int i, int j) {
    if (t[i] - t[j]) return t[i] < t[j];
    return i < j;

}

//从给定字符串T还原原字符串s
void convert(char *t, char *s) {
    int n = 0;
    for (n = 0; t[n]; n++) ind[n] = n;
    sort(ind, ind + n, cmp);
    for (int i = 0, p = ind[0]; i < n; i++, p = ind[p]) {
        s[i] = t[p];
    }
    s[n] = 0;
    return ;

}

struct Node {
    int flag, *ans;
    int next[26], fail;

} tree[2000005];

int que[2000005], head, tail;
int root = 1, cnt = 2;
inline int getNewNode() { return cnt++;  }

//建立字典树
int *insert(char *s) {
    int p = root;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNewNode();
        p = tree[p].next[ind];
    }
    tree[p].flag = 1;
    if (tree[p].ans == NULL) {
        tree[p].ans = new int(0);
    }
    return tree[p].ans;
}

//从字典树建立AC自动机
void build() {
    head = tail = 0;
    tree[root].fail = 0;
    for (int i = 0; i < 26; i++) {
        if (tree[root].next[i] == 0) {
            tree[root].next[i] = root;
            continue;
        }
        tree[tree[root].next[i]].fail = root;
        que[tail++] = tree[root].next[i];
    }
    while (head < tail) {
        int p = que[head++];
        for (int i = 0; i < 26; i++) {
            int c = tree[p].next[i], k = tree[p].fail;
            if (c == 0) {
                tree[p].next[i] = tree[k].next[i];
                continue;
            }
            tree[c].fail = tree[k].next[i];
            que[tail++] = c;
        }
    }
    return ;

}

//匹配
void match(char *s) {
    for (int i = 0, p = tree[root].next[s[0] - 'a'], q, k; s[i]; i++, p = tree[p].next[s[i] - 'a']) {
        q = p;
        while (q) {
            if (tree[q].flag) {
                *tree[q].ans += 1;
            }
            k = q;
            q = tree[q].fail;
            tree[k].fail = 0;
        }
    }
    return ;
}

void init() {
    cnt = 2;
    memset(tree, 0, sizeof(tree));
    memset(ans, 0, sizeof(ans));
    return ;
}

int solve(char *t) {
    init();
    convert(t, s);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        ans[i] = insert(t);
    }
    build();
    match(s + 1);
    for (int i = 0; i < n; i++) {
        cout << (ans[i][0] ? "YES" : "NO") << endl;
    }
    return 0;
}

int main() {
    while (cin >> t) solve(t);
    return 0;
}
