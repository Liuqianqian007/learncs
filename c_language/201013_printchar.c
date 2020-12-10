/*************************************************************************
	> File Name: 20201013_2.c
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 13 Oct 2020 08:43:54 PM CST
 ************************************************************************/

#include<stdio.h>

//输出包含空格的字符串的总字符数
int main() {
    char str[100] = {0};
    //INT ret = 0;
    //[^\n]为正则表达式，表示除了\n外都读入
    while((scanf("%[^\n]s", str)) != EOF){
        getchar();
        printf(" has %d chars\n", printf("%s", str));
    }
    return 0;
}
