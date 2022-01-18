//
// Created by xzh on 2022/1/18.
//

#include "../basic.h"

int main(){
    int arr[2][3]={{1,2,3},{4,5,6}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("size of arr[i] is %d\n", sizeof(arr[0]));
    printf("addr of arr[i] is %p\n", arr[0]);
    printf("size of arr[i] is %d\n", sizeof(arr[1]));
    printf("addr of arr[i] is %p\n", arr[1]);
    return 0;
}