//
// Created by xzh on 2021/6/15.
//

#include "../basic.h"
int swap(int* a,int* b);
#define point_int int *
typedef int* Point_int;
int main(){
    //错误一
    int* a,b;//a是指针类型b是int类型，所以应该写成 int *a,*b;注意*并不是紧贴在int后面
    a=3;//给了警告，a是指针类型
    b=3;
    //错误二
    point_int c,d;//这样c是指针类型，而d是int类型，就会出现问题，这时候就需要使用typedef
    c=3;//给了警告，c是指针类型
    d=3;

    Point_int e,f;//e,f都是指针
    e=3;
    f=3;


}

int swap(int* a,int* b){

}
