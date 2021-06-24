//
// Created by xzh on 2021/6/21.
//

//函数的传指方式

#include "func_point_trans.h"
//void swap_normal(int a,int b,int c) {
//    printf("swap_normal");
//}

void trans_arr();

void swap_normal(int num1, int num2) {
    int tmp = 0;
    tmp = num1;
    num1 = num2;
    num2 = tmp;
    printf("num1=%d num2=%d in func \n", num1, num2);
    printf("num1 addr is %p num2 addr is %p in func \n", &num1, &num2);
}

//double swap_normal( double num1,double  num2) {
//    return num1+num2;
//}

void change_info(const int *id, int *times) {
    // *id=10;
    *times = 100;
}

void swap_by_point(int *num1, int *num2) {
    if (num1 != NULL && num2 != NULL) {
        int tmp = 0;
        tmp = *num1;
        *num1 = *num2;
        *num2 = tmp;
        printf("num1=%d num2=%d in func \n", *num1, *num2);
        printf("num1 addr is %p num2 addr is %p in func \n", num1, num2);
        printf("num1 addr is %p num2 addr is %p in func \n", &num1, &num2);
    } else {
        printf("the args can not be NULL\n");
    }
}

void trans_arr2(int *arr,int size,int value) {
    arr=(int*)malloc(sizeof(int)*size);
    if (arr!=NULL){
        for (int i=0;i<size;i++){
            arr[i]=value;
        }
    }
}

int main() {
    int num1 = 5;
    int num2 = 10;
    // swap_normal(num1,num2);
  //  trans_arr();
     swap_by_point(&num1, &num2);
    printf("num1=%d num2=%d\n", num1, num2);
   printf("num1 addr is %p num2 addr is %p", &num1, &num2);

   // int *vector=NULL;
//    trans_arr2(vector,5,45);


   // printf("%d",*vector);


}

void trans_arr(int **arr,int size,int value) {
    *arr=(int*)malloc(sizeof(int)*size);
    if (*arr!=NULL){
        for (int i=0;i<size;i++){
            *(*arr+i)=value;
        }
    }
}










