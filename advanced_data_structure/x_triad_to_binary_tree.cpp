/*************************************************************************
	> File Name: triad_to_binary_tree.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 04 Feb 2021 09:11:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 【数据结构C++】 根据三元组建立二叉链表 模拟题
 *
 */

typedef struct Node {
    char ch;
    struct Node *lchild, *rchild; 
} Node;

Node *arr[26];

Node *getNewNode(char ch) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->lchild = p->rchild = NULL;
    return p;
}

char str[10];

//输出广义表形式的二叉树
void output(Node *root) {
    if (root == NULL) return ;
    printf("%c", root->ch);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    output(root->lchild);
    if (root->rchild) {
        printf(",");
        output(root->rchild);            
    }
    printf(")");
    return ;
}

int main() {
    Node *root = NULL, *p;
    while (scanf("%s", str)) {
        //结束
        if (str[0] == '^' && str[1] == '^') break;
        //新增结点p并存储在arr数组中
        p = getNewNode(str[1]);
        arr[str[1] - 'A'] = p;
        //根结点
        if (str[0] == '^') {
            root = p;
            continue;                    
        }
        //建立父子结点关系
        switch (str[2]) {
            case 'L': arr[str[0] - 'A']->lchild = p; break;
            case 'R': arr[str[0] - 'A']->rchild = p; break;                    
        }            
    }
    output(root);
    printf("\n");
    return 0;
}
