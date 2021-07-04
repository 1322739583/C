//
// Created by xzh on 2021/7/3.
//

#ifndef C_LIST_H
#define C_LIST_H

typedef int element_type;

typedef struct node *node_prt;
typedef node_prt list_t;
typedef node_prt position;

struct node{
    element_type element;
    node_prt node_next;
};

int is_empty(list_t list);
list_t make_empty(list_t list);

void insert(element_type x,list_t list);
void delete(element_type x,list_t list);
position find(element_type x,list_t list);


#endif //C_LIST_H
