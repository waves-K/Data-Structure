#pragma once 

#include <assert.h>
#include <stdio.h>
#include <malloc.h>

typedef int SDataType;

typedef struct Stack {
    SDataType* _array;
    int _capacity;
    int _size;    // 表示栈中有效元素的个数  2.代表栈顶位置
} Stack;

void Init(Stack* ps) {
    assert(ps);
    ps->_array = (SDataType*)malloc(sizeof(SDataType) * 3);
    if (NULL == ps->_array) {
        assert(0);
        return;
    }

    ps->_capacity = 3;
    ps->_size = 0;;
}

void CheckCapacity(Stack* ps) {
    assert(ps);
    if(ps->_size == ps->_capacity) {
        int newCapacity = ps->_capacity * 2;
        SDataType* pTemp = (SDataType*)malloc(sizeof(SDataType) * newCapacity);
        if (NULL == pTemp) {
            assert(0);
            return;
        }
        for (int i = 0; i < ps->_size; ++i) {
            pTemp[i] = ps->_array[i];
        }

        free(ps->_array);
        ps->_array = pTemp;
        ps->_capacity = newCapacity;
    }
}
void Push(Stack* ps, SDataType data) {
    // 检测是否有空间
    CheckCapacity(ps);

    ps->_array[ps->_size++] = data;
}

int Empty(Stack* ps) {
    assert(ps);

    return 0 == ps->_size;
}

void Pop(Stack* ps) {
    assert(ps);

    if (Empty(ps)) {
        return;
    }

    ps->_size -=1;
}

SDataType Top(Stack* ps) {
    assert(ps);
    return ps->_array[ps->_size - 1];
}

int Size(Stack* ps) {
    assert(ps);

    return ps->_size;
}


void Destroy(Stack* ps) {
    assert(ps);

    if(ps->_array) {
        free(ps->_array);
        ps->_capacity = 0;
        ps->_size = 0;
    }
}
