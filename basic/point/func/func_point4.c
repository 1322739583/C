//
// Created by xzh on 2021/6/24.
//
#include "stdio.h"

typedef int (*funcprt)(int);
int add(int num1,int num2){
    return num1+num2;
}

int sub(int num1,int num2){
    return num1-num2;
}
typedef int (*fptrOperation)(int,int);


fptrOperation selectOp (char op_char){
    switch (op_char) {
        case '+':
            return add;
        case '-':
            return sub;
    }
}

int compute(char op_char,int num1,int num2){
    fptrOperation operation=selectOp(op_char);
    return operation(num1,num2);
}

int main(){
    printf("the add result is %d\n", compute('+',10,2));
    printf("the sub result is %d\n", compute('-',10,2));
}