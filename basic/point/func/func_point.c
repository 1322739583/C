//
// Created by xzh on 2021/6/24.
//
#include "stdio.h"
int (*fptr)(int);
int square(int num){
    return num*num;
}
int main(){
    int num=5;
    fptr=&square;
    printf("%d square is %d",num,fptr(5));
}