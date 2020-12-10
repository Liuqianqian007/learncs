/*************************************************************************
	> File Name: 201112_list.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 12 Nov 2020 06:21:44 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

//链表实现

//data为数据域
//next为指向下一节点的指针
typedef struct ListNode {
    int data;
    struct ListNode* next;//不能省略struct，因为别名目前还不可见
} ListNode;

//此版本链表的head不是指针
//head为虚拟头节点，其中不保存数据
typedef struct List {
    ListNode head;
    int length;
} List;

ListNode *getNewNode(int);
List *getLinkList();
void clear_node(ListNode*);
void clear(List*);
int insert(List *, int, int);
int erase(List *, int);
void reverse(List *);
void output(List *);

int main() {
    srand(time(0));
    #define max_op 20 
    List *l = getLinkList();
    for (int i = 0; i < max_op; i++ ) {
        int val = rand() % 100;
        int ind = rand() % (l->length + 3) - 1;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1: {
                printf("insert %d at %d to list = %d\n", val , ind , insert(l, ind, val));
                break;
            }
            case 2: {
                printf("erase a item at %d from list = %d\n", ind, erase(l, ind));
                break;
            }
            case 3: {
                printf(GREEN("reverse the list!\n"));
                reverse(l);
            }
        }
        output(l), printf("\n");
    }
    #undef max_op
    return 0;
}
//创建节点
ListNode *getNewNode(int val) {
    ListNode *p = (ListNode* )malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}
//创建链表
List *getLinkList() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length = 0;
    return l;
}
//插入元素
int insert(List *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode* p = &(l->head), *node = getNewNode(val);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}
//删除元素
int erase(List *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->length -= 1;
    return 1;
}
//翻转链表！！！
void reverse(List *l) {
    if (l == NULL) return;
    ListNode *p = l->head.next, *q;
    l->head.next = NULL;
    while (p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return;
}
//打印
void output(List *l) {
    if (l == NULL) return;
    printf("List(%d) = [", l->length);
    for (ListNode *p = l->head.next; p; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL]\n");
    return;
}
//销毁节点
void clear_node(ListNode *node) {
    if (node == NULL) return;
    free(node);
    return;
}
//销毁链表
void clear(List *l) {
    if (l == NULL) return;
    //q指向当前结点的下一个结点，防止之后的节点内存泄漏
    ListNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);
    return;
}
