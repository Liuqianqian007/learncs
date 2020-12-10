/*************************************************************************
	> File Name: 201110_vector.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 10 Nov 2020 06:50:11 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

//顺序表实现


//结构定义：
typedef struct Vector {
    //data为指向顺序表中数据地址的指针
    //size为空间大小，length为元素个数
    int *data;
    int size, length;
} Vec;

//结构操作：
//初始化顺序表
Vec *init(int n) {
    Vec *v = (Vec *)malloc(sizeof(Vec));
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return v;
}

//扩容
int expand(Vec *v) {
    int extra_size = v->size;
    int *p;
    while (extra_size) {
        //没开辟成功则返回NULL，因此需要额外的指针p存储返回的地址
        p = (int*)realloc(v->data, sizeof(int) * (v->size + extra_size));
        if (p) break;
        extra_size >>= 1;
    }
    if (extra_size == 0) return 0;
    v->data = p;
    v->size += extra_size;
    return 1;
}

/*
int expand(Vec *v) {
    Vec *old_v = v;
    old_v->data = v->data;
    v->size = old_v->size * 2;
    v = (Vec *)malloc(sizeof(Vec));
    v->data = (int*)malloc(sizeof(int) * v->size);
    for (int i = 0; i < v->size; i++) {
        v[i] = old_v[i];
    }
    free(old_v);
    free(old_v->data);
    old_v = NULL;
    old_v->data = NULL;
    return 1;
}
*/

//插入操作
int insert(Vec *v, int val, int ind) {
    if (v == NULL) return 0;
    if (ind < 0|| ind > v-> length) return 0;
    if (v->length == v->size) {
        if (!expand(v)) return 0;
        printf(GREEN("succuss to expand! the Vector size is %d\n"), v->size);
    }
    for (int i = v->length; i > ind; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

//删除操作
int erase(Vec *v, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind >= v->length) return 0;
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;

}

//清除顺序表
void clear(Vec *v) {
    if (v == NULL) return;
    free(v->data);
    free(v);
    return;
}

//打印
void output(Vec *v) {
    if (v == NULL) return;
    printf("Vector : [");
    for (int i = 0; i < v->length; i++) {
        i && printf(", ");
        printf("%d", v->data[i]);
    }
    printf("]\n");
    return;
}


int main() {
    srand(time(0));
    #define max_op 20
    Vec *v = init(2);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int ind = rand() % (v->length + 3) - 1;//使得随机出来的下标ind范围为-1 ~ length+1
        int op = rand() % 4;
        switch (op) {
            //使得插入操作的概率为75%
            case 0:
            case 1:
            case 2: {
                printf("insert %d at %d to Vector = %d\n", val, ind, insert(v, val, ind));
                break;
            }
            case 3: {
                printf("erase a item at %d from Vector = %d\n", ind, erase(v, ind));
                break;
            }
        }
        output(v);
        printf("\n");
    }
    clear(v);
    return 0;
}
