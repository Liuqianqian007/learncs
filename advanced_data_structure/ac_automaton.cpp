/*************************************************************************
	> File Name: ac_automaton.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 30 Jan 2021 07:02:23 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<memory.h>
using namespace std;

/* 多模匹配——AC自动机 */
#define BASE 26
//结点定义：
//flag表示到当前结点为止是否独立成词
//str表示当flag=1时的单词
//tag为1表示当前结点为字典树本身的结点，为0表示是AC自动机路径压缩产生的结点
//next数组里面的指针指向下一个字符的结点
//fail指向等价匹配结点
typedef struct Node {
    int flag, tag[BASE];
    const char *str;
    struct Node *next[BASE], *fail;
} Node;

//新增结点
int node_cnt = 0;
Node *getNewNode() {
    node_cnt += 1;
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    p->tag[BASE] = {0};
    memset(p->next, 0, sizeof(p->next));
    p->fail = NULL;
    return p;
}

//将单词插入字典树中
void insert(Node *root, const char *str) {
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (root->next[ind] == NULL) root->next[ind] = getNewNode();
        root->tag[ind] = 1;
        root = root->next[ind];
    }
    root->flag = 1;
    root->str = strdup(str);
    return;
}

//从字典树建立AC自动机，即建立等价匹配关系fail
void build_ac(Node *root) {
    //初始化队列q，以便层序遍历AC自动机
    Node **q = (Node **)malloc(sizeof(Node *) * (node_cnt + 5));
    int head = 0, tail = 0;
    root->fail = NULL;
    for (int i = 0; i < BASE; i++) {
        //根结点下一层的路径压缩
        if (root->next[i] == NULL) {
            root->next[i] = root;
            continue;
        }
        //根结点的下一层结点的fail指向根结点
        root->next[i]->fail = root;
        q[tail++] = root->next[i];
    }
    while (head < tail) {
        Node *p = q[head++];
        for (int i = 0; i < BASE; i++) {
            Node *c = p->next[i], *k = p->fail;
            //如果下一结点为空，则继续搜索等价匹配结点
            //路径压缩
            if (c == NULL) {
                p->next[i] = k->next[i];
                continue;
            }
            //等价匹配结点下一层也没有对应字符，则继续搜索下一等价匹配结点
            while (k && k->next[i] == NULL) k = k->fail;
            //如果所有等价匹配结点下一层都没有对应字符，则将等价匹配结点指向根结点
            if (k == NULL) k = root;
            if (k->next[i]) k = k->next[i];
            c->fail = k;
            q[tail++] = c;
        }
    }
    free(q);
    return;
}

void match(Node *root, const char *text) {
    Node *p  = root, *q;
    for (int i = 0; text[i]; i++) {
        int ind = text[i] - 'a';
        //路径压缩后访问等价匹配结点相当于访问下一层结点
        p = p->next[ind];
        q = p;
        //等价匹配结点处如果生成了单词也要输出
        while (q) {
            if (q->flag == 1) printf("find: %s\n", q->str);
            q = q->fail;
        }
    }
    return;

}

void clear(Node *root) {
    if (root == NULL) return;
    for (int i = 0; i < BASE; i++) {
        if (root->tag[i]) clear(root->next[i]);
    }
    free(root);
    return;
}

int main() {
    int n;
    char str[100];
    scanf("%d", &n);
    Node *root = getNewNode();
    //组个输入单词str，建立字典树
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    //从字典树建立AC自动机
    build_ac(root);
    //输入母串，并在AC自动机中查找有哪些单词与母串匹配
    scanf("%s", str);
    match(root, str);
    clear(root);
    return 0;
}


