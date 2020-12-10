/*************************************************************************
	> File Name: 201125_heap_sort.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 25 Nov 2020 08:40:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//线性建堆+堆排序

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

//大顶堆
//n是arr数组的大小，ind是当前元素下标
void downUpdate(int * arr, int n, int ind) {
    //若孩子结点下标没有超过元素个数
    while ((ind << 1) <= n) {
        //l是左孩子，r是右孩子
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        //若孩子结点中有比根结点大的，则找到更大的孩子结点，并与根结点交换
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        //若孩子结点不比根结点大，则停止调整
        if (ind == temp) break;
        swap(arr[temp], arr[ind]);
        //更新当前下标，以便调整下一层
        ind = temp;
    }
    return;
}

//先建堆后排序
void heap_sort(int *arr, int n) {
    //以便用arr[1]访问arr[0]
    arr -= 1;
    //线性建堆：复杂度O(n)
    //从倒数第二层到第一层，每层自上而下遍历
    for (int i = n >> 1; i >= 1; i--) {
        downUpdate(arr, n, i);
    }
    //大顶堆排序：从小到大
    //从第n个元素起，与第一个元素交换，然后从1到n-1调整
    for (int i = n; i > 1; i--) {
        swap(arr[i], arr[1]);
        downUpdate(arr, i - 1, 1);
    }
    return;
}

void output(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
} 


int main () {
    srand(time(0));
    #define max_n 20 
    int *arr = (int *)malloc(sizeof(int) * max_n);
    for (int i = 0; i < max_n; i++) {
        arr[i] = rand() % 100;
    }
    output(arr, max_n);
    heap_sort(arr, max_n);
    output(arr, max_n);
    free(arr);
    #undef max_n

    return 0;
}
