//
// Created by xzh on 2022/1/16.
//

#include "basic.h"

void test01();

void test02();

int main(){
    test01();
    test02();
    return 0;
}
/**
 * 变大的情况
 */
void test02() {
    char *string1;
    char *string2;
    string1=malloc(16);
    strcpy(string1,"0123456789AB");
    string2=realloc(string1,64);
    printf("string1:%p %s\n",&string1,string1);
    printf("string2:%p %s\n",&string2,string2);
}

/**
 * 变小的情况
 */
void test01() {
    char *string1;
    char *string2;
    string1=malloc(16);
    strcpy(string1,"0123456789AB");
    string2=realloc(string1,8);
    printf("string1:%p %s\n",&string1,string1);
    printf("string2:%p %s\n",&string2,string2);
}
