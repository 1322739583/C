//
// Created by xzh on 2021/6/25.
//

#include "basic.h"

int main(){
    int arr[5]={1,2,3,4,5};
    int *ptr=arr;
    ptr[1]=5;//这样是没有问题的
    int a;
    printf("ptr[5]=%d\n",ptr[1]);
    printf("size of arr= %d\n",sizeof(arr));//20字节
    printf("size of int= %d\n",sizeof(a));//在64位系统中，int类型占用4字节
    printf("size of ptr= %d\n", sizeof(ptr));//在64位系统中，int*类型的大小为8字节
    return 0;
}