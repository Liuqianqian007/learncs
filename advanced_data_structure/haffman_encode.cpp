/*************************************************************************
	> File Name: haffman_encode.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Mon 01 Feb 2021 09:42:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*哈夫曼编码*/

#define swap(a, b) {\
    __typeof(a) __c = a;\
    a = b, b = __c;\
}

//哈夫曼树结点定义
//ch结点代表的字符，p概率
typedef struct Node {
    char ch;
    double p;
    struct Node *lchild, *rchild;
} Node;

//新增结点：传入字符ch和概率per，生成结点p
Node *getNewNode(char ch, double per) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->ch = ch;
    p->p = per;
    p->lchild = p->rchild = NULL;
    return p;
}

//两个子树合成一个子树：根结点概率等于俩子结点概率之和
Node *combineNode(Node *a, Node *b) {
    Node *p = getNewNode(0, a->p + b->p);
    p->lchild = a; 
    p->rchild = b;
    return p;
}

//将数组arr中最小的元素排在第n位
void pick_min(Node **arr, int n) {
    for (int j = n - 1; j >= 0; --j) {
        if (arr[n]->p > arr[j]->p) {
            swap(arr[n], arr[j]);
        }
    }
}

//建立哈夫曼树
Node *getHaffmanTree(Node **arr, int n) {
    for (int i = 1; i < n; i++) {
        //选择概率最小和第二小的结点，合成，并将合成的树放在数组倒数第二个位置
        pick_min(arr, n - i);
        pick_min(arr, n - i - 1);
        arr[n - i - 1] = combineNode(arr[n - i], arr[n - i - 1]);
    }
    return arr[0];
}

//编码并输出
void __output_encode(Node *root, char *str, int k) {
    //字符串以空字符结尾
    str[k] = 0;
    if (root->lchild == NULL && root->rchild == NULL) {
        printf("%c %s\n", root->ch, str);
        return;
    }
    //要么有2个孩子结点，要么0个孩子结点
    str[k] = '0';
    __output_encode(root->lchild, str, k + 1);
    str[k] = '1';
    __output_encode(root->rchild, str, k + 1);
    return;
}

void output_encode(Node *root) {
    char str[100];
    __output_encode(root, str, 0);
    return;
}

void clear(Node *root) {
    if (root == NULL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    //arr数组存储haffman树
    Node **arr;
    arr = (Node **)malloc(sizeof(Node *) * n);
    //读入字符ch和出现概率p
    for (int i = 0; i < n; i++) {
        char ch[10];
        double p;
        scanf("%s%lf", ch, &p);
        arr[i] = getNewNode(ch[0], p);
    }
    //生成haffman树
    Node *root = getHaffmanTree(arr, n);
    //从haffman树输出haffman编码
    output_encode(root);
    clear(root);
    free(arr);
    return 0;
}
