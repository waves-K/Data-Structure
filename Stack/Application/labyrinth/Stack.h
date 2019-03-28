#pragma once 

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef struct Position{
    int x;      // ROWS 的下标
    int y;      // COLS 的下标
}   Position;

typedef Position StackDatatype;

// 这里用静态顺序表定义栈
#define MAX_SIZE (100)

typedef struct Stack{
    StackDatatype array[MAX_SIZE];
    int top;    // 等于我们静态顺序表里的 size 
                // 1) top 所在的下标是下一个可用位置
                // 2) top 表示栈里现在有多少数据
}Stack;


// 初始化
void StackInit(Stack* pStack);

// 增(只能从栈顶进行操作) --> 顺序表的尾插
void StackPush(Stack* pStack, StackDatatype data);

// 删(只能从栈顶进行操作) --> 顺序表的头删
void StackPop(Stack* pStack);

// 查(只能查看栈顶元素)
StackDatatype StackTop(const Stack* pStack);

// 元素个数
int StackSize(const Stack* pStack);

// 栈是否满
// 这里虽然是 int 但是返回的是 bool 值
int StackIsFull(const Stack* pStack);

// 栈是否为空
int StackIsEmpty(const Stack* pStack);

// 销毁
void StackDestroy(Stack* pStack);

// 栈的复制
void StackCopy(Stack* pDest, Stack* pSrc);
