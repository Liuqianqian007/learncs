/*************************************************************************
	> File Name: 201112_queue.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 12 Nov 2020 08:20:16 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32) 

//循环队列——解决入队时队列前面有空位却溢出的问题

//在队列的基础上增加cnt字段，表示元素个数
//length表示队列容量
typedef struct Queue {
    int *data;
    int head, tail, length, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof (Queue));
    q->data = (int *) malloc(sizeof(int) * n);
    q->length = n;
    q->head = q->tail = 0;//tail指向最后一个元素的下一个位置
    q->cnt = 0;
    return q;
}

int front(Queue *q) {
    return q->data[q->head];
}
//判空条件改变
int empty(Queue *q) {
    return q->cnt == 0;
}

//扩容：不能用realloc
int expand(Queue *q) {
    int extra_size = q->length;
    int *p;
    while (extra_size) {
        p= (int *) malloc(sizeof(int) * (q->length + extra_size));
        if (p) break;
        extra_size >>= 1;
    }
    if (p == NULL) return 0;
    for (int i = q->head, j = 0; j < q->cnt; j++) {
        p[j] = q->data[(i + j) % q->length];
    }
    free(q->data);
    q->data = p;
    q->length += extra_size;
    q->head = 0;
    q->tail = q->cnt;
    return 1;
}

//扩容错误示范：head和tail不能重置为0和cnt
/*
int expand(Queue *q) {
    int extra_length = q->length;
    int *temp;
    while (extra_length) {
        temp = (int *)realloc(q->data,sizeof(int) * (q->length + extra_length));
        if (temp) break;
        extra_length /= 2;
    }
    if (extra_length == 0) return 0;
    q->data = temp;
    q->length += extra_length;
    q->head = 0;
    q->tail = q->cnt;
    return 1;
}
*/


int push(Queue *q, int val) {
    if (q == NULL) return 0;
    //判满条件改变
    if (q->cnt == q->length) {
        if(!expand(q)) return 0;
        printf(GREEN("expand successfully! Queue->capacity(%d)\n"), q->length);
    }
    q->data[q->tail] = val;
    //尾指针掉头
    q->tail = (q->tail + 1) % q->length;
    q->cnt++;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head++;
    q->cnt--;
    return 1;
}


void output(Queue *q) {
    if (q == NULL) return;
    printf("Queue : [");
    for (int i = q->head, j = 0; j < q->cnt; i++, j++) {
        j && printf(", ");
        //输出元素时掉头
        printf("%d", q->data[i % q->length]);
    }
    printf("]\n");
    return;
}

void clear(Queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return;
}

int main() {
    srand(time(0));
    #define max_op 20 
    Queue *q = init(2);
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
