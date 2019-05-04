#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

typedef unsigned int uint32_t;

typedef struct {
    uint32_t *array;
    unsigned int size;      // 有多少数的信息
    unsigned int capacity;  // array 的容量
} BitArray;

void BitArrayInit(BitArray *pBA) {
    // (unsigned int) -1 就是 2^32 -1
    // 这个是粗略值，没有到 2^32 / 32
    unsigned int capacity = (unsigned int) -1 / 32;
    pBA->capacity = capacity;
    pBA->array = (uint32_t *)malloc(sizeof(uint32_t) * capacity);
    memset(pBA->array, 0, sizeof(uint32_t) * capacity);
    pBA->size = 0;
}

// 把 n 所在 bit 置为 1
void BitArraySet(BitArray *pBA, unsigned int n){
    unsigned int index = n / 32;
    unsigned int bit = n % 32;

    pBA->array[index] |= (1UL << bit);
}

// 把 n 所在 bit 置为 0
void BitArrayZero(BitArray *pBA, unsigned int n){
    unsigned int index = n / 32;
    unsigned int bit = n % 32;

    pBA->array[index] &= ~(1UL << bit);
}

// 返回 n 所在 bit 是否为 1
// 是返回 非零， 不是返回 0
int BitArrayIsOne(BitArray *pBA, unsigned int n){
    unsigned int index = n / 32;
    unsigned int bit = n % 32;

    return pBA->array[index] & (1UL << bit);
}


void Test() {
    BitArray ba;
    BitArrayInit(&ba);

    srand(20190503);
    for (int i = 0; i < 200; ++i) {
        unsigned int n = rand();
        BitArrayIsOne(&ba, n);
    }

    printf("%d\n", BitArrayIsOne(&ba, 350));
}

int main() {
    Test();
    return 0;
}
