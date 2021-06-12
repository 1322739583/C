//
// Created by xzh on 2021/6/10.
//
#include <string.h>
#include <memory.h>
#include <malloc.h>
#include "stdio.h"
#include "assert.h"
#include "stdlib.h"

#define byte unsigned char
#define DEBUG d

void *memCpy(void *pvTo, void *pvFrom, size_t size);
void *memCpy2(void *pvTo, void *pvFrom, size_t size);
void *memCpy3(void *pvTo, void *pvFrom, size_t size);

int main() {
    int length = 10;
    char str[length];
    char strCopy[length];

   // *strCopy = memcpy(malloc(length), str, length);
   memCpy3(NULL,str,length);
}

void *memCpy(void *pvTo, void *pvFrom, size_t size) {
    byte *pbTo = (byte *) pvTo;
    byte *pbFrom = (byte *) pvFrom;
#ifdef DEBUG
    if (pvTo == NULL || pvFrom == NULL) {
        fprintf(stderr, "bad args in memcpy\n");
        abort();
    }
#endif

    while (size-- > 0) {//size自减大于0
        *pbTo++ == *pbFrom++;
        return (pvTo);
    }

}

void *memCpy2(void *pvTo, void *pvFrom, size_t size) {
    byte *pbTo = (byte *) pvTo;
    byte *pbFrom = (byte *) pvFrom;

    assert(pvTo != NULL && pvFrom != NULL);

    while (size-- > 0) {//size自减大于0
        *pbTo++ == *pbFrom++;
        return (pvTo);
    }

}

//..............

#ifdef DEBUG

void _Assert(char *, unsigned);

#define ASSERT(f) \
    if(f)             \
    NULL;            \
    else              \
    _Assert(__FILE__,__LINE__)
#else
#define
ASSERT(f) NULL
#endif


void *memCpy3(void *pvTo, void *pvFrom, size_t size) {
    int a=-1;
    printf("%d",a);

    byte *pbTo = (byte *) pvTo;
    byte *pbFrom = (byte *) pvFrom;

   // assert(pvTo != NULL && pvFrom != NULL);
    ASSERT(pvTo != NULL && pvFrom != NULL);
    while (size-- > 0) {//size自减大于0
        *pbTo++ == *pbFrom++;
        return (pvTo);
    }
    char c=-129;






   // ASSERT(0);

}

void _Assert(char *strFile, unsigned uline) {
    fflush(stdout);
    fprintf(stderr, "\nAssertion failde:%s,line %u\n", strFile, uline);
    fflush(stderr);
    abort();
}

