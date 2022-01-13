//
// Created by xzh on 2022/1/12.
//
#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "memory.h"

struct LinkNode{
    //必须声明为指针类型，不然是非法的，会造成递归声明
    //这是结构体自引用的
    struct LinkNode *next;
    void *data;
};

//一种简单的封装
struct LList{
    //如果改成指针，是不行的
    //在遍历的时候pCurNode为空
    //声明为普通变量和指针类型都是可以的，唯一的区别就是指针类型需要初始化指针
    //也就是需要用malloc给头结点在堆中开辟内存，如果声明为变量，这是在栈中，不需要手动创建。
    //在C语言中，普通变量是声明在栈中。
    struct LinkNode *header;

    int m_size;
};

//真正的LinkList其实是LList,用void*的有点像接口，就是告诉你别管我具体怎么实现的
//直接把LList写成LinKList也是可以的
typedef void * LinkList;


LinkList initLinkList();
void insertLinkList(LinkList list,int pos,void *data);
void foreachLinkList(LinkList list,void (*printList)(void *));
void deleteByPosLinkList(LinkList list,int pos);
void deleteByValueLinkList(LinkList list,void *data,int (*compare)(void *,void *));
void clear(LinkList list);
int sizeLinkList(LinkList list);
void destoryLinkList(LinkList list);
