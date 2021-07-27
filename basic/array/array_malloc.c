//
// Created by xzh on 2021/6/25.
//

#include "basic.h"

#define MAX_SIZE 5

int main() {
    int *ptr = malloc(sizeof(int) * MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; ++i) {
        //方式一
       // ptr[i] = i + 1;
        //方式二
        *(ptr+i)=i+1;
    }

    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("ptr[%d]=%d\n",i,ptr[i]);

    }


    return 0;
}
