#include "calculator-helper.h"

void tips()
{
    puts("欢迎使用LamHo的计算器");
    puts("使用方法如下：");
    puts("\n");
    puts("输入格式为：数字 表达式 数字");
    puts("支持的表达式为：+、-、*、/");
    puts("输入非法表达式将无效!");
    puts("==================");
}

void warning()
{
    puts("输入有误，请按照格式：数字 表达式 数字，进行输入");
    puts("支持的表达式为：+、-、*、/");
}

void isContinue()
{
    puts("按q退出程序，按随意键继续...");
}

void clearBuffer()
{
    while (getchar() != '\n')
    {
        continue;
    }
}