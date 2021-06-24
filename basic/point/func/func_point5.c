//
// Created by xzh on 2021/6/24.
//
#include "stdio.h"

int add(int num1,int num2){
    return num1+num2;
}
int sub(int num1,int num2){
    return num1-num2;
}
typedef int (*fptrOperation)(int,int);
fptrOperation operations[128]={NULL};

int (*fptr[128])(int,int)={NULL};

void initOprationArray(){
    operations['+']=add;
    operations['-']=sub;
}


int computeArray(char op_char,int num1,int num2){
    fptrOperation operation;
    operation=operations[op_char];
    return operation(num1,num2);
}

int main(){
    initOprationArray();
    printf("the add result is %d\n", computeArray('+',10,2));
    printf("the sub result is %d\n", computeArray('-',10,2));
}