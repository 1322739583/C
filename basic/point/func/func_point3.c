//
// Created by xzh on 2021/6/24.
//
#include "stdio.h"
#include "stdlib.h"

typedef int (*funcprt)(int);
int add(int num1,int num2){
    return num1+num2;
}

int sub(int num1,int num2){
    return num1-num2;
}
typedef int (*fptrOperation)(int,int);
int compute(fptrOperation operation,int num1,int num2){
    return operation(num1,num2);
}

int main(){
    int num1=10;
    int num2=2;
    printf("the add result is %d\n", compute(add,num1,num2));
    printf("the sub result is %d\n", compute(sub,num1,num2));
}