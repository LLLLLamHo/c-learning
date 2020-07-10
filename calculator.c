#include <stdio.h>
#include <stdlib.h>
#include "calculator-helper.h"

#define ADD '+'
#define SUBTRACTION '-'
#define MULT '*'
#define DIVISION '/'

int main(void)
{

    tips();

    double first, second;
    char oper;

    while (1)
    {
        puts("请输入计算表达式：");
        int result = scanf("%lf %c %lf", &first, &oper, &second);
        // 清空缓冲区
        clearBuffer();
        // 输入有误
        if (!result || (oper != ADD && oper != SUBTRACTION && oper != MULT && oper != DIVISION))
        {
            printf("==========%c", result);
            warning();
        }
        else
        {
            // 检查
            switch (oper)
            {
            case ADD:
                printf("结果：%.2f\n", first + second);
                break;
            case SUBTRACTION:
                printf("结果：%.2f\n", first - second);
                break;
            case MULT:
                printf("结果：%.2f\n", first * second);
                break;
            case DIVISION:
                printf("结果：%.2f\n", first / second);
                break;
            }

            isContinue();

            if (getchar() == 'q')
            {
                break;
            }
            else
            {
                clearBuffer();
            }
        }
    }

    puts("欢迎下次继续使用LamHo计算器~~ bye!");

    return 0;
}