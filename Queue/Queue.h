#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

typedef struct QNode{
    QDataType data;
    struct QNode* pNext;
}QNode;

typedef struct Queue{
    QNode* pFront;
    QNode* pRear;
    int size;
}Queue;

// 初始化
void QueueInit(Queue* pQ);

// 插到队尾
void QueuePush(Queue* pQ, QDataType data);

// 从队首出列
void QueuePop(Queue* pQ);

// 返回队首数据
QDataType QueueFront(Queue* pQ);

// 返回数据数量
int QueueSize(Queue* pQ);

// 1 表示空  0 表示非空
int QueueIsEmpty(Queue* pQ);

// 销毁
void QueueDestroy(Queue* pQ);
