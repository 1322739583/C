//
// Created by xzh on 2022/1/10.
//

#include "dynamic_array.h"

struct Person {
    char name[20];
    int age;
};

void printPerson(void *data) {
    struct Person *person = data;
    printf("name=%s,age=%d\n", person->name, person->age);
}

int compare(void *data1, void *data2) {
    struct Person *p1 = data1;
    struct Person *p2 = data2;
    return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test01() {
    struct dynamicArray *arr = init_dynamicArray(5);
    struct Person p1 = {"关羽", 33};
    struct Person p2 = {"刘备", 35};
    struct Person p3 = {"曹操", 35};
    struct Person p4 = {"诸葛亮", 27};
    struct Person p5 = {"张飞", 32};
    struct Person p6 = {"赵云", 25};
    struct Person p7 = {"袁绍", 40};

    printf("capacity is %d\n", arr->m_capacity);

    insert_dynamicArray(arr, 0, &p1);
    insert_dynamicArray(arr, 1, &p2);
    insert_dynamicArray(arr, 2, &p3);
    insert_dynamicArray(arr, 3, &p4);
    insert_dynamicArray(arr, 4, &p5);
    insert_dynamicArray(arr, 5, &p6);
    insert_dynamicArray(arr, 6, &p7);

    foreach_dynamicArray(arr, printPerson);

    printf("capacity is %d\n", arr->m_capacity);

    //  deleteByPos_dynamicArray(arr, 1);

    deleteByValue_dynamicArray(arr,&p3,compare);
    deleteByValue_dynamicArray(arr,&p7,compare);
    foreach_dynamicArray(arr, printPerson);

}


int main() {

    test01();
    return 0;
}
