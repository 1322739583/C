//
// Created by xzh on 2021/6/24.
//
#include "stdio.h"

int add(int num1,int num2){
    return num1+num2;
}

typedef int (*fptrOperation)(int,int);

int main(){
    fptrOperation operation=add;
    if (operation==add){
        printf("point to add");
    } else{
        printf("not point to add");
    }
}