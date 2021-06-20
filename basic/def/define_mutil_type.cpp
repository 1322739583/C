//
// Created by xzh on 2021/6/18.
//
#include "stdio.h"
#define DOUBLE(x) ((x)+(x)) //不加括号会出现意想不到的错误
//宏定义可以实现类似泛型的效果，
int main(){
    int a=0,b=0;
    double c=1.2,d=2.3;
    printf("int sum is %d\n",a+b);
    printf("double sum is %1.2lf\n",c+d);
}
