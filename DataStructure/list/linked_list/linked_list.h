//
// Created by xzh on 2021/7/3.
//
/**
 * 自己的思路实现
 */

#ifndef C_LIST_H
#define C_LIST_H

typedef int element_type;
typedef struct node *NodePtr;
typedef NodePtr Node;//node*类型的指针
typedef NodePtr Current;//



struct node{
    element_type element;
    struct node *next;
};

Node init_list(Node list);
int is_empty(Node header);

void printList(Node header);


void insert(element_type x,Node list,Node position);
void delete(element_type x,Node list);
Node find(element_type x,Node list);


#endif //C_LIST_H
