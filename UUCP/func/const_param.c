//
// Created by xzh on 2022/1/18.
//

#include "../basic.h"
void fun(const int *num1,int *num2){
    *num2=*num1;
   // *num1=*num2;
}
void fun2(const int *num1,int *num2){
  //  *num1=100;
    *num2=5;
}
int main(){
    const int a=10;
    int b=5;
   // fun(&21,&b);
    return 0;
}