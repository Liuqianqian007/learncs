/*************************************************************************
	> File Name: 201125_priority_queue.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 25 Nov 2020 07:28:39 PM CST
 ************************************************************************/

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

//堆/优先队列（大顶堆）
typedef struct priority_queue {
    int *data;
    //cnt是大小，size是容量
    int cnt, size;
} priority_queue;

//初始化
priority_queue *init(int n) {
    priority_queue *q = (priority_queue *) malloc(sizeof(priority_queue));
    //从下标1开始存
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->cnt = 0;
    q->size = n;
    return q;
}

//判空
int empty(priority_queue *q) {
    return q->cnt == 0;
}

///获取堆顶元素
int top(priority_queue *q) {
    return q->data[1];
}

//插入元素，并调整使维持大顶堆的性质
int push(priority_queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->size) return 0;
    q->data[++(q->cnt)] = val;
    int ind = q->cnt;
    //父结点存在且比当前结点小，则交换
    while((ind >> 1) && q->data[ind] > q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
} 

//弹出堆顶元素，并调整
int pop(priority_queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    //用最后一个元素覆盖堆顶元素， 并将大小减1
    q->data[1] = q->data[q->cnt--];
    int ind = 1;
    //左孩子结点存在
    while ((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;//等价于r = ind * 2 + 1
        //若有孩子结点大于根结点，找到更大的那个孩子结点，并交换
        if (q->data[l] > q->data[temp]) temp = l;
        if (r <= q->cnt && q->data[r] > q->data[temp]) temp = r;
        //若没有比根结点大的孩子结点，结束遍历
        if (temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        //继续往下一层调整
        ind = temp;
    }
    return 1;
}

//销毁
void clear(priority_queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return;
}

//打印（调试）
void output(priority_queue *q) {
    for (int i = 1; i <= q->cnt; i++) {
        printf("%d, ", q->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    #define max_op 20 
    priority_queue *q = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        push(q, val);
        printf("insert %d to the priority queue!\n", val);
    }
    for (int i = 0; i < max_op; i++) {
        printf("%d ", top(q));
        pop(q);
    }
    printf("\n");
    #undef max_op
    clear(q);
    return 0;
}
