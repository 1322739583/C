//
// Created by xzh on 2021/6/21.
//
#include "../basic.h"

void basic();

void choice_munu();

int main(){
  //  basic();
    choice_munu();
}

void choice_munu() {
    char chioce[11];
    //  printf("please input the number to chioce[0-9]");//输出提示
    // scanf("the choice is %s\n",chioce);//错误，前面加字符串是没有意义的，不会输出，并且chioce在输出时只有一个字符
    scanf("%s\n",chioce);//正确
    printf("your choose %s",chioce);
}

void basic() {//正确
    char str[10];
    scanf("%s",str);

    printf("%s",str);
    //错误
    int num;
    scanf("%d",num);//这是错误的，因为scanf要求传入char*类型
    if (num>80){
        printf("great");
    }
}
