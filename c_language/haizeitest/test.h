/*************************************************************************
	> File Name: test.h
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 03 Nov 2020 06:29:18 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#include<stdio.h>
#include<linklist.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define GREEN_HL(a) COLOR_HL(a, 32) 
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)




//定义TEST宏
//调用add_function()
#define TEST(a, b) \
void a##_##b();\
__attribute__((constructor))\
void add_##a##_##b() {\
    add_function(a##_##b, #a "." #b);\
}\
void a##_##b()

// 泛型宏:根据传入的宏参数a的类型进行对应内容的替换
#define Type(a) _Generic((a), \
    int : "%d",\
    float : "%f",\
    long long : "%lld"\
)

#define P(a, color) {\
    char frm[1000];\
    sprintf(frm, color("%s"), Type(a));\
    printf(frm, a);\
}

#define EXPECT(a, b, cmp) {\
    haizei_test_info.total ++;\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    if (_a cmp _b) haizei_test_info.success++;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s:%d: failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect : " #a " " #cmp " " #b "\n\t\t" "actual : "));\
        P(a,YELLOW_HL);\
        printf(" vs ");\
        P(b,YELLOW_HL);\
        printf("\n\n");\
    }\
    printf(GREEN_HL("[-----------] "));\
    printf("%s %s %s  %s\n", #a, #cmp, #a, _a cmp _b ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
}


#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_LT(a, b) EXPECT(a, b, <)


//#define EXPECT_EQ(a, b) printf("\033[32m[---------]\033[0m%s == %s %s\n", #a, #b, (a) == (b) ? "TRUE" : "FALSE");


//定义TEST宏对应的测试用例函数的函数指针类型
typedef void (*TestFuncT)();

//存放TEST测试用例函数和函数名的结构体,typedef重命名类型
typedef struct Function {
    TestFuncT func;
    const char* func_name;
    struct LinkNode p;
} Function;

typedef struct FunctionInfo {
    int total, success;
} FunctionInfo;

extern FunctionInfo haizei_test_info;

//添加函数及函数名到结构体数组中，并计数
void add_function(TestFuncT func, const char* func_name);


//循环执行结构体数组中的测试用例函数
int RUN_ALL_TESTS();

#endif
