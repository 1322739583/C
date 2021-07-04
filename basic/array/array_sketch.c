//
// Created by xzh on 2021/6/25.
//

#include "basic.h"

int main(){
    //一维数组
    int arr[5]={1,2,3,4,5};
    printf("arr[6]=%d\n",arr[6]);//C语言数组是没有边界限制的，超出边界会取得垃圾值，这要非常小心。
    //二维数组
    int two_d_arr[2][3]={{1,2,3},{4,5,6}};//两行三列
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("two_d_arr[%d][%d]=%d\n",i,j,two_d_arr[i][j]);
        }
    }
    return 0;
}