/*************************************************************************
	> File Name: 201121_hash_table.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 21 Nov 2020 08:15:28 PM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//哈希表
//拉链法

//链表结点定义
typedef struct Node {
    char *str;
    struct Node *next;
} Node;

//哈希表定义:data数组中保存Node的指针
typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

//初始化结点：头插法
Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next  = head;
    return p;
}

//初始化哈希表
HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;//哈希表利用率一般为50%~90%，故大小开2*n
    h->data = (Node **)calloc(h->size, sizeof(Node *));
    return h;
}

//哈希函数
int BKDRHash(char *str) {
    int seed = 31, hash = 0;//seed为素数
    for (int i = 0; str[i]; i++) hash = hash * seed + str[i];
    //0x7fffffff二进制等价于01111111……
    //符号位变成0，其他不变，即取绝对值
    return hash & 0x7fffffff;
}

//插入数据（字符串）
int insert(HashTable *h, char *str) {
    //hash是字符串经哈希函数后的值
    int hash = BKDRHash(str);
    //ind是哈希表下标，h->data[ind]存储第ind个链表的头结点地址
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
}

//查找数据
int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    //当p指针没到链表结尾且不等于要查找的字符串str
    while(p && strcmp(p->str, str)) p = p->next;
    //p为尾指针则没找到
    return p != NULL;
}

//销毁哈希表中某一下标对应的链表
void clear_node(Node *node) {
    if (node == NULL) return;
    Node *p = node, *q;
    while(p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return;
}

//销毁哈希表
void clear_hashtable(HashTable *h) {
    if (h == NULL) return;
    for (int i = 0; i < h->size; i++) {
        clear_node(h->data[i]);
        free(h->data);
        free(h);
        return;
    }
}

int main() {
    int op;
    #define max_n 100
    char str[max_n + 5] = {0};
    HashTable *h = init_hashtable(max_n + 5);
    while (~scanf("%d%s", &op, str)) {
        switch (op) {
            case 0:
                printf("insert %s to HashTable\n", str);
                insert(h, str);
                break;
            case 1:
                printf("search %s from HashTable, result = %d\n", str, search(h, str));
                break;
        }
    }
    #undef max_n
    clear_hashtable(h);
    return 0;
}
