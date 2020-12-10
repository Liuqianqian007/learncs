/*************************************************************************
	> File Name: table_to_tree.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 19 Nov 2020 08:24:03 PM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//由广义表还原二叉树

//二叉树结点定义
typedef struct Node{
    char data;
    struct Node *lchild, *rchild;
} Node;

//二叉树树定义
//n为结点数
typedef struct Tree {
    Node *root;
    int n;
} Tree;

//栈定义：data数组储存栈内元素，栈内元素为二叉树结点的指针，
typedef struct Stack {
    Node **data;
    int top, size;
} Stack;

//初始化树结点
Node *getNewNode(char val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

//初始化二叉树
Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

//初始化栈
Stack *init_stack(int n) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) * n);
    s->top = -1;
    s->size = n;
    return s;
}

//获取栈顶元素
Node *top(Stack *s) {
    return s->data[s->top];
}

//栈的判空
int empty(Stack *s) {
    return s->top == -1;
}

//入栈
int push(Stack *s, Node *val) {
    if (s == NULL) return 0;
    if (s->top == s->size - 1) return 0;
    s->data[++(s->top)] = val;
    return 1;
}

//出栈
int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

//销毁栈
void clear_stack(Stack *s) {
    if (s == NULL) return;
    free(s->data);
    free(s);
    return;
}

//销毁二叉树结点
void clear_node(Node *node) {
    if (node == NULL) return;
    clear_node(node->lchild);
    clear_node(node->rchild);
    free(node);
    return;
}

//销毁二叉树
void clear_tree(Tree *tree) {
    if (tree == NULL) return;
    clear_node(tree->root);
    free(tree);
    return;
}

//从广义表还原二叉树
//传入字符串形式的广义表，node_num记录并传出结点数
Node *build(const char *str, int *node_num) {
    Stack *s = init_stack(strlen(str));
    //flag标记是左孩子还是右孩子
    int flag = 0;
    //temp记录当前入栈的结点，p记录根结点
    Node *temp = NULL, *p = NULL;
    while(str[0]) {
        switch (str[0]) {
            //遇到（则把（前的元素入栈，并把flag标记成zuohaizi
            case '(': {
                push(s, temp);
                flag = 0;
                break;
            }
            //遇到）则把栈顶元素作为根结点并弹出栈顶元素
            case ')': {
                p = top(s);
                pop(s);
                break;
            }
            //遇到，则把flag标记成右孩子
            case ',': {
                flag = 1;
                break;
            }
            //遇到空格什么都不做
            case ' ': break;
            //遇到元素则生成结点和二叉树
            default: {
                temp = getNewNode(str[0]);
                if (!empty(s) && flag == 0) {
                    top(s)->lchild = temp;
                } else if (!empty(s) && flag == 1) {
                    top(s)->rchild = temp;
                }
                ++(*node_num);
                break;
            }
        }
        ++str;
    }
    clear_stack(s);
    //只有一个根节点，没有（）的情况
    if (temp && !p) p = temp;
    return p;
}
//前序遍历
void pre_order_node(Node *root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    pre_order_node(root->lchild);
    pre_order_node(root->rchild);
}

void pre_order(Tree *tree) {
    if (tree == NULL) return;
    printf("pre_order : ");
    pre_order_node(tree->root);
    printf("\n");
    return;
}
//中序遍历
void in_order_node(Node *root) {
    if (root == NULL) return;
    in_order_node(root->lchild);
    printf("%c ", root->data);
    in_order_node(root->rchild);
}

void in_order(Tree *tree) {
    if (tree == NULL) return;
    printf("in_order : ");
    in_order_node(tree->root);
    printf("\n");
    return;
}
//后序遍历
void post_order_node(Node *root) {
    if (root == NULL) return;
    post_order_node(root->lchild);
    post_order_node(root->rchild);
    printf("%c ", root->data);
}

void post_order(Tree *tree) {
    if (tree == NULL) return;
    printf("post_order : ");
    post_order_node(tree->root);
    printf("\n");
    return;
}


int main() {
    char str[1000] = {0};
    int node_num = 0;
    scanf("%[^\n]s", str);
    //由广义表生成二叉树
    Tree *tree = getNewTree();
    tree->root = build(str, &node_num);
    tree->n = node_num;
    //前中后序遍历二叉树
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    return 0;
}
