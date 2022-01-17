//
// Created by xzh on 2022/1/18.
//

#include "../basic.h"
/**
 * 要理解这种区别，需要明白在C语言中，函数和函数直接是没有直接关联的
 * 使用的是不同的栈，要想相互影响，只能通过指针。
 * @param a
 * @param b
 */
void swap(int a,int b){
    int tmp=a;
    a=b;
    b=tmp;
}

void swapByPoint(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main(){
    int num1=3;
    int num2=5;
    swap(num1,num2);
    printf("num1=%d num2=%d\n",num1,num2);
    swapByPoint(&num1,&num2);
    printf("num1=%d num2=%d\n",num1,num2);
    return 0;
}