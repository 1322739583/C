//
// Created by xzh on 2022/1/15.
//

#include "basic.h"

void test01();

void test02();

void test03();

void test04();

void test05();

void test06();

int main() {
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    test06();
    return 0;
}
//编译器认为初始化的=和赋值的=是不一样的
void test06() {
    //直接报错
    //static int *pi=malloc(sizeof(int));
    static int *pi;
    pi=malloc(sizeof(int));
}

//测试初始值是随机数，都说随机的了，浪费时间
void test05() {
    int *pi=malloc(sizeof(1000));
    for (int i = 0; i < 100; ++i) {
        printf("%d ",pi[i]);
    }
    printf("\n");
    for (int i = 100; i < 200; ++i) {
        printf("%d ",pi[i]);
    }
    printf("\n");
    for (int i = 200; i < 300; ++i) {
        printf("%d ",pi[i]);
    }
    printf("\n");
    for (int i = 300; i < 400; ++i) {
        printf("%d ",pi[i]);
    }
    printf("\n");
    for (int i = 400; i < 500; ++i) {
        printf("%d ",pi[i]);
    }
    printf("\n");
    for (int i = 500; i < 600; ++i) {
        printf("%d ",pi[i]);
    }





}

//打印字符串，变量方式不太一样
void test04() {
    //很显然，只有字符串可以这样，还是都用sizeof比较好
    //char *name=malloc(strlen("Susan")+1);
    //这两个方式都是可以的
    char *name = malloc(sizeof("Susan") + 1);
    strcpy(name, "Susan");
    while (*name != 0) {
        printf("%c", *name);
        name++;
    }
}

//每次都会分配新的地址，原来的地址丢失，造成内存泄漏
void test03() {
    int *pi = malloc(sizeof(int));
    printf("%p\n", pi);
    //free(pi);
    pi = malloc(sizeof(int));
    printf("%p\n", pi);
}

//测试数组
void test02() {
    char *pc = malloc(6);
    for (int i = 0; i < 8; ++i) {
        pc[i] = (char) i;
        printf("%d ", pc[i]);
    }

}

//基本使用，分配内存
void test01() {
    int *pi = malloc(sizeof(int));
    *pi = 5;
    printf("*pi=%d\n", *pi);
    //printf("*pi=%d\n", pi);
    printf("*pi=%p\n", pi);
}
