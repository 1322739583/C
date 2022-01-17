//
// Created by xzh on 2022/1/14.
//
#include "memory.h"
#include "stdlib.h"
#include "stdio.h"

#define MAX_SIZE 1024
struct SStack {
    void *data[MAX_SIZE];
    int mSize;
};



typedef void *SeqStack;

SeqStack initSeqStack() {
    struct SStack *stack = malloc(sizeof(struct SStack));
    if (stack == NULL) {
        return NULL;
    }
    //初始化为0
    memset(stack->data, 0, MAX_SIZE);
    stack->mSize = 0;
    return stack;
}

void pushSeqStack(SeqStack stack, void *data) {
    if (stack == NULL) {
        return;
    }
    struct SStack *realStack = stack;
    if (realStack->mSize >= MAX_SIZE) {
        return;
    }
    realStack->data[realStack->mSize] = data;
    realStack->mSize++;
}

void popSeqStack(SeqStack stack) {
    if (stack == NULL) {
        return;
    }
    struct SStack *realStack = stack;
    if (realStack->mSize <= 0) {
        return;
    }
    realStack->data[realStack->mSize - 1] = NULL;
    realStack->mSize--;
}

void *topSeqStack(SeqStack stack) {
    if (stack == NULL) {
        return NULL;
    }
    struct SStack *realStack = stack;
    if (realStack->mSize <= 0) {
        return NULL;
    }
    return realStack->data[realStack->mSize - 1];
}

int sizeSeqStack(SeqStack stack) {
    if (stack == NULL) {
        return -1;
    }
    struct SStack *realStack = stack;
    return realStack->mSize;
}

int isEmptySeqStack(SeqStack stack) {
    if (stack == NULL) {
        return -1;//真
    }
    struct SStack *realStack = stack;
    if (realStack->mSize <= 0) {
        return 1;//真
    }
    return 0;//假
}

void destorySeqStack(SeqStack stack) {
    if (stack == NULL) {
        return;
    }
    free(stack);
    stack = NULL;
}

struct Person {
    char name[20];
    int age;
};


void test01() {

    struct Person p1 = {"关羽", 33};
    struct Person p2 = {"刘备", 35};
    struct Person p3 = {"曹操", 35};
    struct Person p4 = {"诸葛亮", 27};
    struct Person p5 = {"张飞", 32};
    struct Person p6 = {"赵云", 25};
    struct Person p7 = {"袁绍", 40};


    SeqStack stack = initSeqStack();
    pushSeqStack(stack, &p1);
    pushSeqStack(stack, &p2);
    pushSeqStack(stack, &p3);
    pushSeqStack(stack, &p4);
    pushSeqStack(stack, &p5);
    pushSeqStack(stack, &p6);
    pushSeqStack(stack, &p7);

    struct Person *p;
    p = topSeqStack(stack);
    printf("name=%s,age=%d\n", p->name, p->age);
    for (int i = 0; i < 8; ++i) {
        popSeqStack(stack);
        p = topSeqStack(stack);
        printf("name=%s,age=%d\n", p->name, p->age);
    }

}

int main() {
    test01();
    return 0;
}


