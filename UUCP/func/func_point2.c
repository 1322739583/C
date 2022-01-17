//
// Created by xzh on 2022/1/18.
//

#include "../basic.h"

int square(int num) {
    return num * num;
}

typedef int (*funptr)(int);


int main() {
    funptr fun1;
    fun1 = square;

    printf("square of num is %d\n", fun1(10));
    return 0;
}