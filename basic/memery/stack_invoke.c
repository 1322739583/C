//
// Created by xzh on 2021/7/27.
//

#include "../basic.h"
int* func1(){
    int a=10;
    return &a;
}
//这个例子还是很难的
char * func2(){
    //声明为char*结果不同
    char str[]="hello";
    return str;
}
int main(){
//    int *p=func1();
//    printf("*p =%d",*p);
//    printf("*p =%d",*p);
    char *p=NULL;
    p=func2();
    printf("*p =%s\n",p);
    printf("*p =%s\n",p);
    return 0;
}