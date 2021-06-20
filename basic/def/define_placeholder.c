//
// Created by xzh on 2021/6/18.
//
#include "stdio.h"
#define PRINT(FORMAT,VALUE) \
printf("THE value of " #VALUE \
" is " FORMAT "\n",VALUE)

int main(){
    int x=0;

    PRINT("%d",x);//THE value of x is 0
    PRINT("%d",x+3);//THE value of x+3 is 3
    return 0;
}
