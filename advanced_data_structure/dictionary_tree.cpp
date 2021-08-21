/*************************************************************************
	> File Name: dictionary_tree.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 29 Jan 2021 11:31:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BASE 26
/* 字典树 */

//结点定义：
//flag记录到该结点为止是否独立成词
//next记录该结点的孩子结点包括哪些字符
typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

//创建结点
Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(p->next));
    return p;
}

//为字符串s创建字典树
void insert(Node *p, const char *s) {
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return;
}

void clear(Node *root) {
    if (root == NULL) return;
    for (int i = 0; i <BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return;
}

//字符串排序：深度优先遍历整棵字典树
void output(Node *root, int k, char *s) {
    //字符串结尾储存空字符
    s[k] = 0;
    //独立成词则输出
    if (root->flag) {
        printf("%s\n", s);
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        s[k] = 'a' + i;
        output(root->next[i], k + 1, s);
    }
    return;
}

int main() {
    int n;
    char str[100];
    scanf("%d", &n);
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    //将全集中的所有字符串按字典序排序输出
    output(root, 0, str);
    clear(root);
    return 0;
}
