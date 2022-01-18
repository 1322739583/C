//
// Created by xzh on 2022/1/12.
//

#include "link_list.h"


LinkList initLinkList() {
    struct LList *list = malloc(sizeof(struct LList));
    if (list == NULL) {
        return NULL;
    }
    list->m_size = 0;
    list->header = malloc(sizeof(struct LinkNode));
    // list->header=NULL;

    return list;
}

void insertLinkList(LinkList list, int pos, void *data) {
    if (list == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }
    struct LList *real_list = list;
    //插入是有size+1个位置的
    if (pos < 0 || pos > real_list->m_size) {
        return;
    }

    struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
    if (NULL == newNode) {
        return;
    }

    //
    //查找node的前一个node
    struct LinkNode *curNode = real_list->header;
    for (int i = 0; i < pos; i++) {
        curNode = curNode->next;
    }

    newNode->data = data;
    newNode->next = curNode->next;
    curNode->next = newNode;
    real_list->m_size++;
}

void foreachLinkList(LinkList list, void (*printList)(void *)) {
    struct LList *real_list = list;
    if (NULL == list) {
        return;
    }

    struct LinkNode *pCurNode = real_list->header->next;
    for (int i = 0; i < real_list->m_size; i++) {
        printList(pCurNode->data);
        pCurNode = pCurNode->next;
    }
}

void deleteByPosLinkList(LinkList list, int pos) {
    if (list == NULL) {
        return;
    }
    struct LList *real_list = list;
    //删除只有size个位置,插入有n+1个位置
    if (pos < 0 || pos >= real_list->m_size) {
        return;
    }
    struct LinkNode *curNode = real_list->header;
    for (int i = 0; i < pos; ++i) {
        curNode = curNode->next;
    }
    //有必要可以返回这个节点
    struct LinkNode *pDel = curNode->next;
    curNode->next = pDel->next;
    free(pDel);
    pDel = NULL;
    real_list->m_size--;
}

void deleteByValueLinkList(LinkList list, void *data, int (*compare)(void *, void *)) {

    if (list == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }
    struct LList *real_list = list;
    //根据数据删除的时候当前位置和前一个位置是都不知道的
    struct LinkNode *prevNode = real_list->header;
    struct LinkNode *curNode = prevNode->next;
    for (int i = 0; i < real_list->m_size; ++i) {
        if (compare(data, curNode->data)) {
            prevNode->next = curNode->next;
            free(curNode);
            curNode = NULL;
            real_list->m_size--;
            break;
        }
        prevNode = prevNode->next;
        curNode = curNode->next;
    }

}

void clear(LinkList list) {
    if (list==NULL){
        return;
    }
    struct LList *real_list=list;
    struct LinkNode *curNode=real_list->header;
    for (int i = 0; i < real_list->m_size; ++i) {
        //记录下一个节点，因为当前节点要删掉了
        struct LinkNode *nextNode=curNode->next;
        free(curNode);
        curNode=nextNode;
    }
    //
    real_list->header->next=NULL;
    real_list->m_size=0;
}

int sizeLinkList(LinkList list){
    if (list==NULL){
        return -1;
    }
    struct LList *real_list=list;
    return real_list->m_size;
}

void destoryLinkList(LinkList list){
    if (list==NULL){
        return;
    }
    clear(list);
    free(list);
    list=NULL;
}

void *findByValueLinkList(LinkList list,void *data,void* (*findString)(void *data)){
    if (list==NULL){
        return NULL;
    }

    if (data==NULL){
        return NULL;
    }

    return findString;
}


struct Person {
    char name[20];
    int age;
};

void printList(void *data) {
    struct Person *p = data;
    printf("name=%s,age=%d\n", p->name, p->age);
}

int compare(void *data1, void *data2) {
    struct Person *p1 = data1;
    struct Person *p2 = data2;
    return strcmp(p1->name, p2->name) == 0 && (p1->age == p2->age);
}

void test01() {

    struct Person p1 = {"关羽", 33};
    struct Person p2 = {"刘备", 35};
    struct Person p3 = {"曹操", 35};
    struct Person p4 = {"诸葛亮", 27};
    struct Person p5 = {"张飞", 32};
    struct Person p6 = {"赵云", 25};
    struct Person p7 = {"袁绍", 40};


    LinkList list = initLinkList();
    insertLinkList(list, 0, &p1);
    insertLinkList(list, 1, &p2);
    insertLinkList(list, 2, &p3);
    insertLinkList(list, 3, &p4);
    insertLinkList(list, 4, &p5);
    insertLinkList(list, 5, &p6);
    insertLinkList(list, 6, &p7);
    foreachLinkList(list, printList);
    printf("list size is %d\n",sizeLinkList(list));
    deleteByPosLinkList(list, 2);

    printf("...........\n");

    foreachLinkList(list, printList);
    printf("list size is %d\n",sizeLinkList(list));
    deleteByValueLinkList(list, &p7, compare);
    printf("...........\n");
    foreachLinkList(list, printList);
    printf("list size is %d\n",sizeLinkList(list));
    clear(list);
    foreachLinkList(list, printList);
    printf("...........\n");
    insertLinkList(list, 0, &p1);
    foreachLinkList(list, printList);
    printf("list size is %d\n",sizeLinkList(list));
    destoryLinkList(list);

}

int main() {
    test01();
    return 0;
}



