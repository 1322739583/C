//
// Created by xzh on 2022/1/9.
//
#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "memory.h"

struct dynamicArray {
    //void** 相对于int* p，double* p
    void **pAddr;
    int m_capacity;
    int m_size;
};

struct dynamicArray *init_dynamicArray(size_t capacity);

void insert_dynamicArray(struct dynamicArray *array, int pos, void *data);

void foreach_dynamicArray(struct dynamicArray *array, void (*fun_foreach)(void *));

void deleteByPos_dynamicArray(struct dynamicArray *array, int pos);

void deleteByValue_dynamicArray(struct dynamicArray *arr, void *data, int(*compare)(void *, void *));

void destory_dynamicArray(struct dynamicArray *arr);

