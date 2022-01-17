//
// Created by xzh on 2022/1/18.
//

#include "../basic.h"

int add(int num1,int num2) {
    return num1+ num2;
}

int sub(int num1,int num2) {
    return num1-num2;
}

typedef int (*ptrOperation)(int,int);

int compute(ptrOperation operation,int num1,int num2){
    return operation(num1,num2);
}


int main() {
    printf("computed num is %d\n", compute(add,10,20));
    printf("computed num is %d\n", compute(sub,10,20));
    return 0;
}