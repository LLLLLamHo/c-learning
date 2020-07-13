#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(int argc, char *argv[])
{

    FILE *in, *out;
    int ch;

    char name[LEN]; // 输出文件名

    int count = 0;

    // 检查入参
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 打开文件
    if ((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // 设置输出
    // 复制文件名并保留5个字节空位
    strncpy(name, argv[1], LEN - 5);

    // 截取字符串
    name[LEN - 5] = '\0';
    // 合并字符串，strcat遇到\0会结束，将name\0之后加上.red
    strcat(name, ".red");

    // 写文件方式打开，找到文件会覆盖，没有找到会新建
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    // 拷贝数据
    while ((ch = getc(in)) != EOF)
    {
        // 每3个字符拷贝一个去输出文件
        if (count++ % 3 == 0)
        {
            putc(ch, out);
        }
    }

    if (fclose(in) != 0 || fclose(out) != 0)
    {
        fprintf(stderr, "Error in closing files\n");
    }

    return 0;
}