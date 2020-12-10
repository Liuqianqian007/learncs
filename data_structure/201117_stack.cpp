/*************************************************************************
	> File Name: 201117_stack.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 17 Nov 2020 07:45:26 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

//栈的实现
//size是容量，top是栈顶元素
typedef struct Stack {
    int *data;
    int size, top;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *) malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
} 

int top(Stack *s) {
    return s->data[s->top];
}

int empty(Stack *s) {
    return s->top == -1;
}

int expand(Stack *s) {
    int extra_size = s->size;
    int *p;
    while (extra_size) {
        p = (int *)realloc(s->data, sizeof(int) * (s->size + extra_size));
        if (p != NULL) break;
        extra_size /= 2;
    }
    if (p == NULL) return 0;
    s->data = p;
    s->size += extra_size;
    return 1;
}

int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top == s->size - 1) {
        if (!expand(s)) return 0;
        printf(GREEN("expand successfully! Stack->size = (%d)\n"), s->size);
    }
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void output(Stack *s) {
    if (s == NULL) return;
    printf("[");
    for (int i = 0; i <= s->top; i++) {
        i && printf(", ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    return;
}

void clear(Stack *s) {
    if (s == NULL) return;
    free(s->data);
    free(s);
    return;
}

int main() {
    srand(time(0));
    #define max_op 20 
    Stack *s = init(4);
    int flag;
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to the Stack = %d\n", val, push(s, val));
                break;
            }
            case 3: {
                //放在一行可能先执行pop再执行top，因此要分开
                flag = !empty(s);
                flag && printf("pop %d from the Stack", top(s));
                printf("result = %d\n", pop(s));
                break;
            }
        }
        output(s), printf("\n");
    }
    #undef max_op
    clear(s);
    return 0;
}
