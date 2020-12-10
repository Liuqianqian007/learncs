/*************************************************************************
	> File Name: 201112_queue.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 12 Nov 2020 08:20:16 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//队列

//data为存储数据的数组
//head为队首元素下标
//tail为尾后元素下标
//length表示容量
typedef struct Queue {
    int *data;
    int head, tail, length;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof (Queue));
    q->data = (int *) malloc(sizeof(int) * n);
    q->length = n;
    q->head = q->tail = 0;//tail指向最后一个元素的下一个位置
    return q;
}
//获取队首元素的值
int front(Queue *q) {
    return q->data[q->head];
}
//判断队列是否为空
int empty(Queue *q) {
    return q->head == q->tail;
}
//入队
int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->tail == q->length) return 0;
    q->data[q->tail] = val;
    q->tail++;
    return 1;
}
//出队
int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head++;
    return 1;
}
//打印
void output(Queue *q) {
    if (q == NULL) return;
    printf("Queue : [");
    for (int i = q->head, j = 0; i < q->tail; i++, j++) {
        j && printf(", ");
        printf("%d", q->data[i]);
    }
    printf("]\n");
    return;
}
//清空
void clear(Queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return;
}

int main() {
    srand(time(0));
    #define max_op 20 
    Queue *q = init(10);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to the Queue! ", val);
                printf("result = %d\n", push(q, val));
                break;
            }
            case 3: {
                printf("pop %d from the Queue! ", front(q));
                printf("result = %d\n", pop(q));
                break;
            }
        }
        output(q), printf("\n");
    }
    clear(q);
    return 0;
}
