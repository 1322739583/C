//
// Created by xzh on 2021/7/4.
//
#include "stdio.h"
#include "time.h"


//结构体的基本结构

//     struct tag {
//        member-list
//     } variable-list;

//tag:标签，并不能理解为struct的类型，因为struct的类型是由变量列表的类型决定的。
//menber-list：成员列表
//variable-list:变量列表


//形式一：
//struct {
//    int a;
//    char b;
//    float c;
//} x;
//
//struct {
//    int a;
//    char b;
//    float c;
//}y[20],*z;//变量列表
//形式二：
//struct SIMPLE{
//    int a;
//    char b;
//    float c;
//};
//名字重复，要使用把前面重复的注释了
//struct SIMPLE x;
//struct SIMPLE y[20],*z;

//形式三：
typedef struct SIMPLE{//SIMPLE这个名字存在的意义不大
    int a;
    char b;
    float c;
}Simple;

typedef struct {//有了变量列表，tag的用处就不大了，所以省略
    int a;
    char b;
    float c;
}simple2;

//用tag来声明变量的时候，struct是不可以省略的
struct SIMPLE x;//正确，是在声明变量
struct SIMPLE *z;//正确，是在声明变量

typedef struct SIMPLE x2;//这是在取别名，而不是声明
typedef struct SIMPLE *z2;

//一个较复杂的例子
struct COMPLEX{
    float f;
    int a[20];
    long *lp;
    struct SIMPLE s;
    struct SIMPLE sa[10];
    struct SIMPLE *sp;
};

struct SELF_REF1{
    int a;
    //struct SELF_REF1 b;//非法
    struct SELF_REF1 *b;//合法
    int c;
};

 typedef struct {
    int a;
    struct SELF_REF2 *b;
    int c;
}SELF_REF2;

//不完整声明
struct B;
 struct A{
     struct B *p;
 };

 struct B{
     struct A *p;
 };

 //初始化
 struct INIT_EX{
     int a;
     short b[10];
     Simple c;
 }ex={
         10,
         {1,2,3,4,5},
         {10,'a',1.0}
 };
#define PRODUCT_SIZE 10
 typedef struct {
     char product[PRODUCT_SIZE];
     int quantity;
     float unit_price;
     float total_amount;
 }Transaction;

 void print_receipt(register Transaction const *trans){

 }

int main(){
    //间接引用
    //
    int start,end;
    start=clock();
  struct COMPLEX *c;
    (*c).f;
    c->f;
    printf( "%d\n",sizeof(int*));
    printf( "%d\n",sizeof(long*));
    printf( "%d\n",sizeof(struct COMPLEX));
    printf( "%d\n",sizeof(c));

    struct SELF_REF1 b;

    SELF_REF2  s;
    s.b=1;


    struct A a;
    a.p->p;


    printf("result=%d\n",2<<2);

    end=clock();
    printf("use time %d ms\n",end-start);

}


