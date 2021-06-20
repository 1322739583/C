//
// Created by xzh on 2021/6/18.
//
#define DEBUG 0//定义为1或者0

#include "stdio.h"

#if DEBUG
#define PRINTF \
printf("is debug mode\n");
#else
#define PRINTF \
printf("is release mode\n");
#endif

//这种判断方式和ifdef是一样的
#if defined(DEBUG)
#define NEXT_DEF printf("#if defined(DEBUG)\n");
#endif

#ifdef NEXT_DEF 这里可以直接 \
写注释 但是不推荐这样做  还是直接用注释符号比较好
#define SECOND_DEF printf("#ifdef NEXT_DEF\n");
#endif
//判断未定义
#if !defined(DEBUG)
#define THIRD_DEF printf("#if !defined(DEBUG)\n");
#endif

#ifndef FOURTH_DEF
#define FOURTH_DEF printf("#ifndef DEBUG\n");
#endif


int main() {
    PRINTF
    NEXT_DEF
    SECOND_DEF
    //THIRD_DEF//没定义到（ndef 或者 if !define）是取不到的
    //FOURTH_DEF


}