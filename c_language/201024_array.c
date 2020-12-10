/*************************************************************************
	> File Name: 201024_array.c
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 24 Oct 2020 07:42:21 PM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 100

void func(int (*num)[3][2]) {
    printf("num = %p, num + 1 = %p\n", num, num + 1);//相差3 * 4?
}

int main() {
    int arr[100][3][2];//开辟的地址在栈区,系统栈为8MB
    printf("sizeof(arr) = %lu\n", sizeof(arr));//1280000 = 320000 * 4
    printf("&arr = %p, &arr[0] = %p\n", arr, &arr[0]);//相等
    printf("arr + 1 = %p, arr + 2 = %p\n", arr + 1, arr + 2);//相差6 * 4？
    char *p = (char *)arr;
    printf("p + 1 = %p, p + 2 = %p\n",p + 1, p + 2);//相差1
    func(arr);
    printf("arr = %p, arr + 1 =%p\n", arr, arr + 1);//相差6 * 4?
    int **q;
    printf("q = %p, q + 1 = %p\n", q, q + 1);//相差8
    return 0;
}
