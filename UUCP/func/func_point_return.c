//
// Created by xzh on 2022/1/18.
//

#include "../basic.h"

typedef int (*funcPtr)(int, int);

int add(int num1, int num2) {
    return num1 + num2;
}

int sub(int num1, int num2) {
    return num1 - num2;
}

funcPtr selectOp(char c) {
    switch (c) {
        case '+':
            return add;
        case '-':
            return sub;
    }
}

int compute(char opcode, int num1, int num2) {
    funcPtr op = selectOp(opcode);
    op(num1, num2);
}

int main() {
    int result = compute('+', 10, 20);
    printf("result=%d\n", result);
    int result2 = compute('-', 10, 20);
    printf("result=%d\n", result2);
    return 0;
}