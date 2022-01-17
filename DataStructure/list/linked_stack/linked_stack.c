//
// Created by xzh on 2022/1/14.
//
//C语言在多个文件的时候是不能有相同名字的
//这导致名字普遍都比较长
#include "stdio.h"
#include "stdlib.h"
#define MAX_SIZE 1024

struct StackNode{
    void *data;
    struct LinkNode *next;
};

struct LStack{
    struct StackNode *mHeader;
    int mSize;
};

typedef void * LinkedStack;

LinkedStack initLinkedStack(){
    struct LStack *stack=malloc(sizeof(struct LStack));
    if (stack==NULL){
        return NULL;
    }
    stack->mHeader=malloc(sizeof(struct StackNode));
    stack->mSize=0;
    return stack;
}
/**
 * 在链表头插入，这样不需要遍历到链表尾
 * @param stack
 * @param data
 */
void pushSeqStack(LinkedStack stack,void *data){
    if(stack==NULL){
        return;
    }
    struct LStack *real_stack=stack;
    if (real_stack==NULL){
        return;
    }
    struct StackNode *newNode=malloc(sizeof(struct StackNode));
    if (newNode==NULL){
        return;
    }
    newNode->data=data;
    newNode->next=real_stack->mHeader;
    real_stack->mHeader=newNode;
}

void *topLinkedStack(LinkedStack stack){
    if (stack==NULL){
        return NULL;
    }
    struct LStack *real_stack=stack;
    if (real_stack->mSize>=MAX_SIZE){
        return NULL;
    }
    struct StackNode *topNode=real_stack->mHeader->next;
    return topNode->data;
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


    LinkedStack stack = initLinkedStack();
    pushSeqStack(stack, &p1);
    pushSeqStack(stack, &p2);
    pushSeqStack(stack, &p3);
    pushSeqStack(stack, &p4);
    pushSeqStack(stack, &p5);
    pushSeqStack(stack, &p6);
    pushSeqStack(stack, &p7);

    struct Person *p;
    p = topLinkedStack(stack);
    printf("name=%s,age=%d\n", p->name, p->age);
//    for (int i = 0; i < 8; ++i) {
//        popSeqStack(stack);
//        p = topSeqStack(stack);
//        printf("name=%s,age=%d\n", p->name, p->age);
//    }

}

int main() {
    test01();
    return 0;
}