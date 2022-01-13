//
// Created by xzh on 2021/12/3.
//

//移位运行，对应2.1.9

//#include "../../basic.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "inttypes.h"


//自己找到了一个itoa的实现

char* itoa(int num,char* str,int radix)
{/*索引表*/
    char index[]="0123456789ABCDEF";
    unsigned unum;/*中间变量*/
    int i=0,j,k;
    /*确定unum的值*/
    if(radix==10&&num<0)/*十进制负数*/
    {
        unum=(unsigned)-num;
        str[i++]='-';
    }
    else unum=(unsigned)num;/*其他情况*/
    /*转换*/
    do{
        str[i++]=index[unum%(unsigned)radix];
        unum/=radix;
    }while(unum);
    str[i]='\0';
    /*逆序*/
    if(str[0]=='-')
        k=1;/*十进制负数*/
    else
        k=0;

    for(j=k;j<=(i-1)/2;j++)
    {       char temp;
        temp=str[j];
        str[j]=str[i-1+k-j];
        str[i-1+k-j]=temp;
    }
    return str;
}


int main(){
    int a=0b01100011>>4;
    int b=0b10010101>>4;
    char ch=0b11111;
    long long l=123456;
    short   sh=-123;
    int8_t shsh=10;
    unsigned int c=-8;
    int d=0xfffffffff;
    printf("a=%x\n",a);
    printf("b=%x\n",b);
    printf("c=%u\n",c);
    printf("ch=%x\n",ch);
    printf("%d\n",sizeof(l));
    printf("%d\n",sizeof(shsh));
    printf("x = %" PRId32 ", y= %" PRIu64 "\n",a,b);
    char s[25];
    itoa(a,s,2);
    printf("%s\n",s);
    itoa(b,s,2);
    printf("%s\n",s);


    return 0;
}