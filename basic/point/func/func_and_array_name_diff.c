//
// Created by xzh on 2021/6/25.
//
#include "stdio.h"
void fun(int *p,int n){

}

int main(){
    printf("fun :%p\n",fun);
    printf("&fun :%p\n",&fun);

    int arr[5]={1,2,3,4,5};
    printf("arr:%p\n",arr);
    printf("&arr:%p\n",&arr);

    int *p=*arr+1;
    printf("*(arr+1):%d\n",*(arr+1));//表示首地址移动一个数组单元，结果为a[1],值为2。
    printf("*(&arr+1):%d\n",*(&arr+1));//(&arr+1)表示从首地址移动sizeof(int)*5个内存单元。

    (*(void(*) ())0x100000)();
    ((void(*) ())0x100000)();//写成这样也对
}