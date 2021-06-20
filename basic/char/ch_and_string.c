//
// Created by xzh on 2021/6/20.
//
#include "string.h"
#include "stdio.h"


/**
 * 修改字符串的值
 */
void change_str() {
    char *str = "Sound";
    *str = "L";//signal 11 SIGSEGV,段违例
    printf("str=%s\n", str);
}

/**
 * 初始化字符串
 */
void init_str() {
    char c='a';//'a'字符字面量是int类型的
    char d='abcd';//C语言实际上是没有char类型，char类型是用int类型来表示的，所以放四个字符字面量也没有报错
    printf("%c",d);//输出d,32位int前24位放着’abc‘后面8位放着’d‘,'abc'被截取了。
   // char *str = "abcde";
   // char *s = 'a';//这行并不会段违例

    //printf("%s", s);//signal 11 SIGSEGV 段违例

    //通过输入流初始化
    char * s;
    scanf("%s",s);
    printf("%s\n",s);//SIGSEGV 段违例
}

int main() {
    //change_str();
    init_str();
    return 0;
}

