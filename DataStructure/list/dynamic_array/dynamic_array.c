//
// Created by xzh on 2022/1/9.
//

#include "dynamic_array.h"

struct dynamicArray *init_dynamicArray(size_t capacity) {
    if (capacity <= 0) {
        return NULL;
    }

    struct dynamicArray *array = malloc(sizeof(struct dynamicArray));

    if (NULL == array) {
        return NULL;
    }

    array->m_capacity = capacity;
    array->m_size = 0;
    array->pAddr = malloc(sizeof(void *) * capacity);

    return array;
}

void insert_dynamicArray(struct dynamicArray *array, int pos, void *data) {
    if (NULL == array) {
        return;
    }
    if (pos < 0 || pos > array->m_size) {
        return;
    }
    if (NULL == data) {
        return;
    }
    if (array->m_size >= array->m_capacity) {
        int newCapacity = array->m_capacity * 2;
        void **newSpace = malloc(sizeof(void *) * newCapacity);
        memcpy(newSpace, array->pAddr, sizeof(void *) * array->m_capacity);

        free(array->pAddr);
        array->pAddr = newSpace;
        array->m_capacity = newCapacity;

    }

    for (int i = array->m_size - 1; i >= pos; i--) {
        array->pAddr[i + 1] = array->pAddr[i];
    }

    array->pAddr[pos] = data;
    array->m_size++;

}

void foreach_dynamicArray(struct dynamicArray *array, void (*fun_foreach)(void *)) {
    if (NULL == array) {
        return;
    }
    if (NULL == fun_foreach) {
        return;
    }
    for (int i = 0; i < array->m_size; i++) {
        fun_foreach(array->pAddr[i]);
    }
}

void deleteByPos_dynamicArray(struct dynamicArray *array, int pos) {
    if (NULL == array) {
        return;
    }
    if (pos < 0 || pos >= array->m_size) {
        return;
    }
    for (int i = pos; i < array->m_size - 1; i++) {
        //不小心把i写成position
        array->pAddr[i] = array->pAddr[i + 1];
    }
    array->m_size--;
}

void deleteByValue_dynamicArray(struct dynamicArray *arr, void *data, int(*compare)(void *, void *)) {
    if (NULL == arr) {
        return;
    }
    if (NULL == data) {
        return;
    }
    for (int i = 0; i < arr->m_size; i++) {
        if (compare(arr->pAddr[i], data)) {
            deleteByPos_dynamicArray(arr, i);
        }
    }
}

void destory_dynamicArray(struct dynamicArray *arr){
    if (NULL==arr){
        return;
    }
    if (arr->pAddr!=NULL){
        free(arr->pAddr);
        arr->pAddr=NULL;
    }
    free(arr);
    arr=NULL;
}

