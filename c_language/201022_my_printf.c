/*************************************************************************
	> File Name: 201022_my_printf.c
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 22 Oct 2020 07:08:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdarg.h>
#include<inttypes.h>

//用可变参数函数实现简版printf函数

//先翻转一遍，因为output函数输出时翻转了
int rev_num(int n, int *temp) {
    int digit = 0;
    *temp = 0;
    do {
        *temp = *temp * 10 + n % 10;
        n /= 10;
        ++digit;
    }while(n);
    return digit;
}

int output_num(int n, int digit) {
    int cnt = 0;
    while(digit--) {
        putchar(n % 10 + 48), ++cnt;//'0'的ASCII码为48
        n /= 10;
    }
    return cnt;
}

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;//定义指针，用于存储可变参数地址
    va_start(arg, frm); //初始化指针，使其指向第一个可变参数，该宏第二个参数是变参列表的前一个参数，即最后一个固定参数
    #define PUTC(a) putchar(a), ++cnt
    for (int i = 0; frm[i]; i++) { //字符串结尾'\0'等于十进制0，即循环到字符串结尾结束
        switch (frm[i]) {
            case '%': {
                switch (frm[++i]) {
                    case '%': PUTC(frm[i]);break;
                    case 'd': {
                        int xx = va_arg(arg, int);//该宏返回变参列表当前参数并使指针指向下一变参，其第二个参数是变参类型
                        uint32_t x;//若用int类型，INT32_MIN取绝对值后溢出（INT32_MIN的绝对值比INT32_MAX的绝对值大1）
                        if (xx < 0) PUTC('-'),x = -xx;
                        else x = xx;
                        int temp1, temp2;
                        int x1 = x /100000, x2 = x % 100000;//2^31-1是10位数，分成两部分输出，解决翻转后溢出问题
                        int digit1 = rev_num(x1, &temp1);
                        int digit2 = rev_num(x2, &temp2);
                        if (x1) digit2 = 5;
                        else digit1 = 0;
                        cnt += output_num(temp1, digit1);
                        cnt += output_num(temp2, digit2);
                    } break;
                    case 's': {
                        const char* str = va_arg(arg, const char *);
                        for (int i = 0; str[i]; i++) {
                            PUTC(str[i]);
                        }
                    } break;
                }
            } break;
            default: PUTC(frm[i]); break;
        }
    }
    #undef PUTC
    va_end(arg);//结束变参获取
    return cnt;
}

int main() {
    //int n;
    //while (~scanf("%d", &n)) {
        //printf(" has %d digitals\n", printf("%d", n));
        //my_printf(" has %d digitals\n", my_printf("%d", n));
    //}
    
    int a = 123;
    printf("hello world\n");
    my_printf("hello world\n");
    printf("int(a) = %d\n", a);
    my_printf("int(a) = %d\n", a);
    printf("int(a) = %d\n", 0);
    my_printf("int(a) = %d\n", 0);
    printf("int(a) = %d\n", 1000);
    my_printf("int(a) = %d\n", 1000);
    printf("int(a) = %d\n", -123);
    my_printf("int(a) = %d\n", -123);
    printf("int(a) = %d\n", INT32_MAX);
    my_printf("int(a) = %d\n", INT32_MAX);
    printf("int(a) = %d\n", INT32_MIN);
    my_printf("int(a) = %d\n", INT32_MIN);

    char str[100] = "I love China";
    printf("int(a) = %s\n", str);
    my_printf("int(a) = %s\n", str);
    return 0;
}
