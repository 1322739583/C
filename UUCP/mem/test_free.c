//
// Created by xzh on 2022/1/16.
//
#include "basic.h"

void test01();

void test02();

void test03();

int main(){
    //test01();
     test02();
  // test03();
    return 0;
}
/**
 * 重复free测试2
 * 不明显的例子
 */
void test03() {
    int *p1=malloc(sizeof(int));
    int *p2=p1;
    free(p1);
    p1=NULL;
    free(p1);
    //p2=NULL;

}

/**
 * 重复free测试1
 */
void test02() {
    int *pi=malloc(sizeof(int));
    *pi=5;
    free(pi);
     pi=NULL;//加了这行就不会报错
    free(pi);
}

/**
 * free不能管理&获取的地址，只能管理malloc相关的内存分配
 */
void test01() {
    int num;
    int *p=&num;
    free(p);

}
