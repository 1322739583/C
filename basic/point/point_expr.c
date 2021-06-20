//
// Created by xzh on 2021/6/20.
//

#include "stdio.h"
#include "stdlib.h"
size_t strlen(char* );

int main(){
    char* str="123456";
    char   a="dddd";
    int len=strlen(str);
    printf("%d",len);
    return 0;
}

size_t strlen(char* string){
    int length=0;
    while(*string++!='\0'){
        length+=1;
    }
    return length;
}