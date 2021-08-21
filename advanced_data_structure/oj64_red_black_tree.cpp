/*************************************************************************
	> File Name: red_black_tree_insert.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 23 Dec 2020 08:23:34 PM CST
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
/*红黑树*/

//结构定义
typedef struct Node {
    int key;
    //结点颜色：0 red, 1 black, 2 double black
    int color;
    struct Node *lchild, *rchild;
} Node;

//定义NIL结点
Node __NIL;
#define NIL (&__NIL) 
//先于主函数执行
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->color = 1;
    NIL->lchild = NIL->rchild = NIL;
    return;
}

//新增结点
Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = 0;
    p->lchild = p->rchild = NIL;
    return p;
}

//销毁
void clear(Node *root) {
    if (root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}

//判断是否有红色孩子结点
int has_red_child(Node *root) {
    return root->lchild->color == 0 || root->rchild->color == 0;
}

//左旋
Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

//右旋
Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

//插入调整！！！
Node *insert_maintain(Node *root) {
    //没有红色孩子结点
    if (!has_red_child(root)) return root;
    //???
    //情况2：flag标记冲突发生在左子树还是右子树，1 左子树，2 右子树
    int flag = 0;
    if (root->lchild->color == 0 && has_red_child(root->lchild)) flag = 1;
    if (root->rchild->color == 0 && has_red_child(root->rchild)) flag = 2;
    //没有冲突
    if (flag == 0) return root;
    //情况1：可以不判断是否冲突，没冲突调整了也不影响平衡
    if (root->lchild->color == 0 && root->rchild->color == 0) {
        //染色：红色上浮
        root->color = 0;
        root->lchild->color = root->rchild->color = 1;
        return root;
    }
    if (flag == 1) {
        //小左旋
        if (root->lchild->rchild->color == 0) {
            root->lchild = left_rotate(root->lchild);
        }        
        //大右旋
        root = right_rotate(root);
    } 
    else {
        //小右旋
        if (root->rchild->lchild->color == 0) {
            root->rchild = right_rotate(root->rchild);
        }
        //大左旋
        root = left_rotate(root);
    }
    //染色：红色上浮
    root->color = 0;
    root->lchild->color = root->rchild->color = 1;
    return root;

}

//插入新结点
Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    //递归插入
    if (key < root->key) {
        root->lchild = __insert(root->lchild, key);
    }
    else {
        root->rchild = __insert(root->rchild, key);
    }
    //回溯时调整
    return insert_maintain(root);
}

//封装插入操作，将根结点染黑
Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = 1;
    return root;
}

//寻找度为2的结点的前驱
Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

//删除调整！！！
Node *erase_maintain(Node *root) {
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    //情况4：有兄弟结点是红色
    if (has_red_child(root)) {
        //标记旋转方向，1 右旋，2 左旋
        int flag = 0;
        //原根结点染红
        root->color = 0;
        //左兄弟是红色，右旋
        if (root->lchild->color == 0) {
            root = right_rotate(root);
            flag = 1;
        }
        //右兄弟是红色，左旋
        else {
            root = left_rotate(root);
            flag = 2;
        }
        //新根结点染黑
        root->color = 1;
        //左旋则往右递归，右旋则往左递归
        if (flag == 1) root->rchild = erase_maintain(root->rchild);
        else root->lchild = erase_maintain(root->lchild);
        return root;
    }
    //情况1：兄弟结点和两个侄子结点都是黑色
    if ((root->lchild->color == 2 && !has_red_child(root->rchild)) ||
        (root->rchild->color == 2 && !has_red_child(root->lchild))) {
        root->lchild->color -= 1;
        root->rchild->color -= 1;
        root->color += 1;
        return root;
    }
    //情况2：左子树是双重黑
    if (root->lchild->color == 2) {
        //if成立则是RL型，if不成立则是RR型
        if (root->rchild->rchild->color != 0) {
            //兄弟子树旧根染红
            root->rchild->color = 0;
            //小右旋
            root->rchild = right_rotate(root->rchild);
            //兄弟子树新根染黑
            root->rchild->color = 1;
        }
        //大左旋
        root = left_rotate(root);
        //根结点染成原根结点颜色
        root->color = root->lchild->color;
        //双重黑结点减一重黑???
        root->lchild->lchild->color -= 1;

    }
    //情况3：右子树是双重黑
    else {
        if (root->lchild->lchild->color != 0) {
            //兄弟子树旧根染红
            root->lchild->color = 0;
            //小右旋
            root->lchild = left_rotate(root->lchild);
            //兄弟子树新根染黑
            root->lchild->color = 1;
        }
        //大右旋
        root = right_rotate(root);
        //根结点染成原根结点颜色
        root->color = root->rchild->color;
        //双重黑结点减一重黑???
        root->rchild->rchild->color -= 1;
        
    }
    //两个子结点染黑
    root->lchild->color = root->rchild->color = 1;
    return root;
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return NIL;
    if (key < root->key) {
        root->lchild = __erase(root->lchild, key);
    }
    else if (key > root->key) {
        root->rchild = __erase(root->rchild, key);
    }
    else {
        //删除度为0或度为1的结点
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            temp->color += root->color;
            free(root);
            return temp;
        }
        //删除度为2的结点
        else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

//封装删除操作，将根结点染黑
Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = 1;
    return root;
}

//打印结点信息（颜色| 根， 左， 右）
void print_node(Node *root) {
    printf("%d %d %d %d\n", root->key, root->color, root->lchild->key, root->rchild->key);
    return;
}

//中序遍历
void output(Node *root) {
    if (root == NIL) return;
    output(root->lchild);
    print_node(root);
    output(root->rchild);
    return;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
            case 3: output(root);
        }
    }
    return 0;
}
