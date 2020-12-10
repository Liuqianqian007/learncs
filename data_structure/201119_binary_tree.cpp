/*************************************************************************
	> File Name: binary_tree.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 19 Nov 2020 07:26:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//二叉树

//定义结点：数据，左孩子指针，右孩子指针
typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

//定义树：根节点指针，结点数
typedef struct Tree {
    Node *root;
    int n;
} Tree;

//初始化结点
Node *getNewNode(int val) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

//初始化树
Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

//销毁结点:递归销毁以此结点为根的二叉树
void clearNode(Node *node) {
    if (node == NULL) return;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return;
}

//销毁树
void clear(Tree *tree) {
    if (tree == NULL) return;
    clearNode(tree->root);
    free(tree);
    return;
}

//二叉排序树插入结点
Node *insert_node(Node *root, int val, int *flag) {
    //成功插入，flag表示结点数加1
    if (root == NULL) {
        *flag = 1;
        return getNewNode(val);
    }
    //插入值等于当前结点值
    if (val == root->data) return root;
    //插入值小于当前结点值
    if (val < root->data) root->lchild = insert_node(root->lchild, val, flag);
    //插入值大于当前结点值
    else root->rchild = insert_node(root->rchild, val, flag);
    return root;
}

//往二叉排序树中插入元素
void insert(Tree *tree, int val) {
    int flag = 0;
    tree->root = insert_node(tree->root, val, &flag);
    tree->n += flag;
    return;
}

//前序遍历
void pre_order_node(Node *node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    pre_order_node(node->lchild);
    pre_order_node(node->rchild);
    return;
}
void pre_order(Tree *tree) {
    if (tree == NULL) return;
    printf("pre_order : ");
    pre_order_node(tree->root);
    printf("\n");
    return;
}
//中序遍历
void in_order_node(Node *node) {
    if (node == NULL) return;
    in_order_node(node->lchild);
    printf("%d ", node->data);
    in_order_node(node->rchild);
    return;
}
void in_order(Tree *tree) {
    if (tree == NULL) return;
    printf("in_order : ");
    in_order_node(tree->root);
    printf("\n");
    return;
}
//后序遍历
void post_order_node(Node *node) {
    if (node == NULL) return;
    post_order_node(node->lchild);
    post_order_node(node->rchild);
    printf("%d ", node->data);
    return;
}

void post_order(Tree *tree) {
    if (tree == NULL) return;
    printf("post_order : ");
    post_order_node(tree->root);
    printf("\n");
    return;
}

//打印广义表：结点操作
void output_node(Node *root) {
    if (root == NULL) return;
    printf("%d", root->data);
    if (root->lchild == NULL && root->rchild ==NULL) return;
    printf("(");
    output_node(root->lchild);
    printf(", ");
    output_node(root->rchild);
    printf(")");
    return;
}

//打印广义表
void output(Tree *tree) {
    if (tree == NULL) return;
    printf("tree(%d) : ", tree->n);
    output_node(tree->root);
    printf("\n");
    return;
}


int main() {
    srand(time(0));
    Tree *tree = getNewTree();
    #define max_op 10
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        insert(tree, val);
        output(tree);
    }
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    #undef max_op
    free(tree);
    return 0;
}
