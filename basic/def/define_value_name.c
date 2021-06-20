//
// Created by xzh on 2021/6/18.
//
#include "stdio.h"
#define FOR(BASE_NAME,COUNT) \
for(int i=0;i<<5;i++){    \
    printf("the value of " #BASE_NAME  "%d is %d\n",COUNT,BASE_NAME##COUNT);                     \
}
/**
 * 想实现输出x1=0,x2=0,x3=0这样的结果，但是好像是不能实现的,i这个变量是不会被解析成数字的
 * @return
 */
int main(){
    int x=0;
    int x2=0;
    int x3=0;
    FOR(x,3)
    return 0;
}
