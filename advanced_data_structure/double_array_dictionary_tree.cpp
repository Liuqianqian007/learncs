/*************************************************************************
	> File Name: double_array_dictionary_tree.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Mon 01 Feb 2021 10:22:03 PM CST
 ************************************************************************/

#include<string.h>
#include<cstdio>
#include<cstdlib>
using namespace std;

/* 双数组字典树 + AC自动机 */

#define BASE 26
#define MSG_LEVEL 1
#define DEBUG_LEVEL 1
#define INFO_LEVEL 2
#define LOG(level, frm, args...) {\
    if (level >= MSG_LEVEL) {\
        printf(frm, ##args);\
    }\
}

#define LOG_DEBUG(args...) LOG(DEBUG_LEVEL, args)
#define LOG_INFO(args...) LOG(INFO_LEVEL, args)

//字典树结点定义
typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

//双数组字典树结点定义
typedef struct DANode {
    int base, check, fail;
} DANode;

//新增字典树结点
Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(p->next));
    return p;
}

inline int code(char c) { return c - 'a'; }

//建立字典树：将单词str插入字典树中
int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = code(str[i]);
        if (p->next[ind] == NULL) {
            cnt += 1;
            p->next[ind] = getNewNode();
        }
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}

//清除字典树
void clear_tree(Node *root) {
    if (root == NULL) return;
    for (int i = 0; i < BASE; i++) {
        clear_tree(root->next[i]);
    }
    free(root);
    return;
}

//枚举法计算每个父结点的base值
int get_base_value(Node *root, DANode *tree) {
    int base = 1, flag_base;
    do {
        base += 1;
        flag_base = 1; 
        for (int i = 0; i < BASE && flag_base; i++) {
            if (root->next[i] == NULL) continue;
            //如果使用当前base值得到的子结点坐标与已存在的结点冲突，则结束本次循环，base + 1
            if (tree[base + i].check) flag_base = 0;
        }
    } while (flag_base == 0);
    return base;
}

//从字典树建立双数组字典树，返回最大下标
int double_array_trie(Node * root, DANode *tree, int ind) {
    if (root == NULL) return 0;
    //独立成词则check值为负数
    if (root->flag) tree[ind].check = -tree[ind].check;
    //获取当前结点的base值
    int base = get_base_value(root, tree);
    tree[ind].base = base;
    //当前结点的子结点的check值为当前结点的下标
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree[base + i].check = ind;
    }
    int max_ind = ind;
    for (int i = 0; i < BASE; i++) {
        int temp = double_array_trie(root->next[i], tree, base + i);
        if (temp > max_ind) max_ind = temp;
    }
    return max_ind;
}

//输出加入AC自动机的双数组字典树的信息
void dump_double_array_trie(DANode *tree, int n) {
    LOG_INFO("%d\n", n);
    for (int i = 0; i <= n; i++) {
        LOG_INFO("%d %d %d\n", tree[i].base, tree[i].check, tree[i].fail);
    }
    return;
}

//从双数组字典树建立AC自动机
void ac_double_array_trie(DANode *tree, int max_ind) {
    int *que = (int *)malloc(sizeof(int) * (max_ind + 5));
    int head, tail;
    head = tail = 0;
    tree[1].fail = 0;
    //根结点处的路径压缩
    for (int i = 0; i < BASE; i++) {
        int child_ind = tree[1].base + i;
        if (abs(tree[child_ind].check) != 1) continue;
        tree[child_ind].fail = 1;
        que[tail++] = child_ind;
    }
    while (head < tail) {
        int p = que[head++];
        for (int i = 0; i < BASE; i++) {
            int c = tree[p].base + i, k = tree[p].fail;
            if (abs(tree[c].check) != p) continue;
            while (k && abs(tree[tree[k].base + i].check) != k) k = tree[k].fail;
            if (k == 0) k = 1;
            if (abs(tree[tree[k].base + i].check) == k) k = tree[k].base + i;
            tree[c].fail = k;
            que[tail++] = c;
        }
    }
    free(que);
    return;
}

int main() {
    int n, cnt = 1; 
    scanf("%d", &n);
    char str[1000];
    //建立字典树
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    //建立双数组字典树
    size_t tree_size = sizeof(DANode) * (cnt *BASE);
    DANode * tree = (DANode *)malloc(tree_size);
    memset(tree, 0, tree_size);
    int max_ind = double_array_trie(root, tree, 1);
    //计算压缩比(不加AC自动机时，压缩比为0.04，即压缩了BASE - 1倍)
    size_t s1 = cnt * sizeof(Node);
    size_t s2 = max_ind * sizeof(DANode);
    LOG_DEBUG("trie(%lu Byte), double array trie(%lu Byte)\n", s1, s2);
    LOG_DEBUG("rate : %2.1lf\n", 1.0 * s2 / s1);
    //输出双数组字典树的信息
    for (int i = 0; i <= max_ind; i++) {
        LOG_DEBUG("(%d | %d, %d)\t", i, tree[i].base, tree[i].check);
        if ((i + 1) % 5 == 0) LOG_DEBUG("\n");
    }
    LOG_DEBUG("\n");
    //在双数组字典树中加入AC自动机并输出信息
    ac_double_array_trie(tree, max_ind);
    dump_double_array_trie(tree, max_ind);
    free(tree);
    clear_tree(root);
    return 0 ;
}
