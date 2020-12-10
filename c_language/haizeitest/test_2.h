/*************************************************************************
	> File Name: test.h
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 03 Nov 2020 06:29:18 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

extern int success_cnt;
extern int cnt;

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

#define EXPECT(a, b, cmp) \
if (!((a)cmp(b))) {\
    printf(YELLOW_HL("\n\t"__FILE__":%d:") YELLOW_HL("failure\n"), __LINE__);\
    printf(YELLOW_HL("\t\texpect : "#a" "#cmp" "#b"\n"));\
    printf(YELLOW_HL("\t\tactual : %d vs %d\n\n"),a, b);\
}\
printf(GREEN_HL("[-----------] "));\
printf("%s %s %s %s\n", #a, #cmp, #b, (a) cmp (b) ? (success_cnt++, GREEN_HL("TRUE")) : RED_HL("FALSE"));\
cnt++;


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
} Function;

//添加函数及函数名到结构体数组中，并计数
void add_function(TestFuncT func, const char* func_name);


//循环执行结构体数组中的测试用例函数
int RUN_ALL_TESTS();

#endif
