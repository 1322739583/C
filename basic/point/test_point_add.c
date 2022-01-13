/**
 * 深入理解C指针 p20,p21
 **/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int *p = NULL;
    int num = 0;
    p = &num;
    printf("............int point..............\n");
    printf("the addr size is %d\n", sizeof(p));
    printf("the addr p is %p\n", p);
    p += 1;
    //不管32位还是64位，都是+4，因为int*的大小是4个字节
    printf("the new addr p is %p\n", p);

    short s;
    short *ps = &s;
    printf("............short point..............\n");
    printf("the addr ps is %p\n", ps);
    ps += 1;
    //移动2个字节
    printf("the new addr ps is %p\n", ps);

    char c;
    char *pc = &c;
    printf("............char point..............\n");
    printf("the addr pc is %p\n", pc);
    pc += 1;
    //移动1个字节
    printf("the new addr pc is %p\n", pc);

    //@TODO这个需要再看看

    int n;
    void *pv = &n;
    printf("............void point..............\n");
    printf("the addr size is %d\n", sizeof(pv));
    printf("the addr pv is %p\n", pv);
    //不是标准行为
    pv = pv + 1;
    //并没有想书上说的会给警告
    //非常奇怪的是，并没有移动4个字节，而是只移动1个字节
    //建议是不要用，不是C语言标准行为，不同编译器会出现不同结果
    printf("the new addr pv is %p\n", pv);

    printf("............sub point by value..............\n");

    int vector[] = {28, 41, 7};
    int *pi = vector + 2;
    printf("%d\n", *pi);
    pi--;
    printf("%d\n", *pi);
    pi--;
    printf("%d\n", *pi);
    printf("............sub point by point..............\n");
    //这种方式可以用来确定数组元素顺序
    int arr[] = {28, 41, 7};
    int *p0 = arr + 0;
    int *p1 = arr + 1;
    int *p2 = arr + 2;
    printf("%d\n", p2 - p0);
    printf("%d\n", p2 - p1);
    printf("%d\n", p0 - p1);

    printf("............compare point..............\n");
    //也可以用来确定数组元素顺序1表示true，0表示false
    int arr2[] = {28, 41, 7};
    int *pa0 = arr2 + 0;
    int *pa1 = arr2 + 1;
    int *pa2 = arr2 + 2;
    printf("%d\n", pa2 > pa0);
    printf("%d\n", pa2 < pa1);
    printf("%d\n", pa0 > pa1);

    return 0;
}