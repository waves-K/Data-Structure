#pragma once 

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef int StackDatatype;

// 这里用静态顺序表定义栈
#define MAX_SIZE (100)

typedef struct Stack{
    StackDatatype arry[MAX_SIZE];
    int top;    // 表示当前个数
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
int StackFull(const Stack* pStack);

// 栈是否为空
int StackEmpty(const Stack* pStack);

// 销毁
void StackDestroy(Stack* pStack);
