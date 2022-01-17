//
// Created by xzh on 2022/1/18.
//

#include "../basic.h"
int square(int num){
    return num*num;
}
int (*fptr)(int);



int main(){
    fptr=&square;
    int *a;

    printf("square of num is %d\n",fptr(10));
    return 0;
}