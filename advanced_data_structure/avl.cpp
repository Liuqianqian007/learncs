/*************************************************************************
	> File Name: avl.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 22 Dec 2020 08:33:11 PM CST
 ************************************************************************/

#include<cstdio>
#include<cstdlib>
/*AVL树*/

#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define H(n) (n->h)


//定义
typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

//虚拟空结点，作用是替代NULL，使得访问NULL的数据字段的行为合法
Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0, NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return;
}

//新增结点
Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

//更新树高
void update_height(Node *root) {
    root->h = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1;
    return;
}

//左旋操作
Node *left_rotate(Node *root) {
    //temp指向旋转后的根结点地址
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}

//右旋操作,与左旋对称
Node *right_rotate(Node *root) {
    //temp指向旋转后的根结点地址
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}


//调整！
Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    //左子树大于右子树，LL或LR
    if (root->lchild->h > root->rchild->h) {
        //LR
        if(root->lchild->lchild->h < root->lchild->rchild->h) {
            root->lchild = left_rotate(root->lchild);
        }
        //大右旋
        root = right_rotate(root);
    } 
    //右子树大于左子树，RR或RL
    else {
        //RL
        if(root->rchild->rchild->h < root->rchild->lchild->h) {
            root->rchild = right_rotate(root->rchild);
        }
        //大左旋
        root = left_rotate(root);

    }
}

//插入
Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) {
        root->lchild = insert(root->lchild, key);
    }
    else {
        root->rchild = insert(root->rchild, key);
    }
    update_height(root);
    return maintain(root);
}

//查找度为2的结点的前驱
Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while(temp->rchild) temp = temp->rchild;
    return temp;
}

//删除
Node *erase(Node *root, int key) {
    if (root == NIL) return NIL;
    if (key < root->key) {
        root->lchild = erase(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node * temp = root->lchild != NIL? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, key);
        }
    }
    update_height(root);
    return maintain(root);
}

//销毁
void clear(Node *root) {
    if (root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}

void print_node(Node *root) {
    printf("(%d[%d], %d, %d)\n", root->key, root->h, root->lchild->key, root->rchild->key);
    return;
}

void output(Node *root) {
    if (root == NIL) return;
    print_node(root);
    output(root->lchild);
    output(root->rchild);
    return;
}


int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 0: root = erase(root, val); break;
            case 1: root = insert(root, val); break;
        }
        output(root);
        printf("---------------\n");
    }

    return 0;
}
