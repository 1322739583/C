//
// Created by xzh on 2021/6/24.
//
#include "stdio.h"
#include "stdlib.h"

typedef int (*funcprt)(int);
int square(int num){
    return num*num;
}

int main(){
    int num=5;
    funcprt fptr2;
    fptr2=square;
    printf("%d square is %d",num,fptr2(5));


}