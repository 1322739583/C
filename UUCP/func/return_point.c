//
// Created by xzh on 2022/1/18.
//

#include "../basic.h"

int *allocateArray(int size, int value) {
    int arr[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
    }
    return arr;
}

int *allocateArray2(int size, int value) {
    int *arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
    }
    return arr;
}

int *allocateArray3(int size, int value) {
    static int arr[5];
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
    }
    return arr;
}

void allocateArray4(int **arr,int size,int value){
    *arr=malloc(sizeof(int));
    if (*arr!=NULL){
        for (int i = 0; i < size; ++i) {
            //*(*arr[i])=value;
            *(*arr+i)=value;
        }
    }
}


int main() {

    //int *vector=allocateArray(5,45);
    // int *vector=allocateArray2(5,45);
    //int *vector = allocateArray3(5, 45);

//    for (int i = 0; i < 5; ++i) {
//        printf("%d\n", vector[i]);
//    }

    int *vector=NULL;
    allocateArray4(&vector,5,45);
    printf("%p\n",vector);
    return 0;
}