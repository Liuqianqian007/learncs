/*************************************************************************
	> File Name: 201031_pointer2.c
	> Author: liuqian
	> Mail: 
	> Created Time: Mon 02 Nov 2020 08:09:42 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//强转为char类型，因为char为一字节
/*
#define offset(T, a) ({\
    T temp;\
    (char *)(&temp.a) - (char *)(&temp);\
})
*/

#define offset(T, a) (long)(&(((T*)(NULL))->a))

//define为简单字符替换
#define ppchar char*
typedef char* pchar;

struct Data {
    char a;//0
    double b;//8
    char c[2];//16
    char d;//18
    int e;//19 //24
};

void output(int argc, char* argv[], char** env) {
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i,  argv[i]);
    }
    for (int i = 0; env[i]; i++) {
        //printf("env[%d] = %s\n", i, env[i]);
        //指纹密码，用户是否匹配
        if (!strncmp(env[i], "USER=", 5)) {
            if (!strcmp(env[i] + 5, "liuq")) {
                printf("welcome!\n");
            } else {
                printf("you are not the user!\n");
                exit(0);
            }
        }
    }
    return;
}


int main(int argc, char* argv[], char** env) {
    //小端机，存储顺序为64/63/62/61/0
    //十六进制数转为字符分别对应dcba，其中0为字符串结尾标志
    int num = 0x061626364;
    printf("%s\n", (char *)(&num));

    printf("%ld\n", offset(struct Data, a));
    printf("%ld\n", offset(struct Data, b));
    printf("%ld\n", offset(struct Data, c));
    printf("%ld\n", offset(struct Data, d));
    printf("%ld\n", offset(struct Data, e));
    printf("%ld\n", sizeof(struct Data));

    ppchar p1, p2;
    pchar p3, p4;
    printf("p1 : %lu, p2 : %lu\n", sizeof(p1), sizeof(p2));
    printf("p3 : %lu, p4 : %lu\n", sizeof(p3), sizeof(p4));

    output(argc, argv, env);
    return 0;
}
