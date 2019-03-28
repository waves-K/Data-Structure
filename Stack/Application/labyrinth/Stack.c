#include"Stack.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

// 初始化
void StackInit(Stack* pStack){
    assert(pStack != NULL);
    pStack->top = 0;
}

// 增
void StackPush(Stack* pStack, StackDatatype data){
    assert(pStack != NULL);
    assert(pStack->top < MAX_SIZE);     // 保证栈空间没满

    pStack->array[pStack->top++] = data;
}

// 删
void StackPop(Stack* pStack){
    assert(pStack != NULL);     // 保证栈存在
    assert(pStack->top > 0);    // 保证栈里边有元素

    pStack->top--;
}

// 查
StackDatatype StackTop(const Stack* pStack){
    assert(pStack->top > 0);

    return pStack->array[pStack->top - 1];
}

// 元素个数
int StackSize(const Stack* pStack){
    return pStack->top;
}

// 栈是否满
int StackIsFull(const Stack* pStack){
    return pStack->top >= MAX_SIZE;
}

// 栈是否为空
int StackIsEmpty(const Stack* pStack){
    return pStack->top <= 0;
}

void StackCopy(Stack* pDest, Stack* pSrc){
    pDest->top = pSrc->top;

    memcpy(pDest->array, pSrc->array, pSrc->top * sizeof(StackDatatype));
}

// 销毁
void StackDestroy(Stack* pStack){
    assert(pStack != NULL);
    pStack->top = 0;
}
