//
// Created by xzh on 2022/1/16.
//

#include "basic.h"

void test01();

int main(){
    test01();
    return 0;
}
/**
 * calloc会将分配的内存制空，相反，malloc只分配内存，所以需要考虑是否需要制空。
 */
void test01() {
    int *pi=calloc(20, sizeof(int));

    //int *pi=malloc(5* sizeof(int));
    //memset(pi,0,5*sizeof(int));
    for (int i = 0; i < 20; ++i) {
        printf("%d ",pi[i]);
    }

}

