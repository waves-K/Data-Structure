#include"Stack.h"

// 初始化
void StackInit(Stack* pStack){
    pStack->top = 0;
}

// 增
void StackPush(Stack* pStack, StackDatatype data){
    assert(pStack->top < MAX_SIZE);

    pStack->arry[pStack->top++] = data;
}

// 删
void StackPop(Stack* pStack){
    assert(pStack != NULL);
    assert(pStack->top > 0);

    pStack->top--;
}

// 查
StackDatatype StackTop(const Stack* pStack){
    assert(pStack->top > 0);

    return pStack->arry[pStack->top - 1];
}

// 元素个数
int StackSize(const Stack* pStack){
    assert(pStack != NULL);

    return pStack->top;
}

// 栈是否满
int StackFull(const Stack* pStack){
    assert(pStack != NULL);

    return pStack->top >= MAX_SIZE;
}

// 栈是否为空
int StackEmpty(const Stack* pStack){
    assert(pStack != NULL);

    return pStack->top == 0 ? 1 : 0;
}

// 销毁
void StackDestroy(Stack* pStack){
    assert(pStack != NULL);

    pStack->top = 0;
}
