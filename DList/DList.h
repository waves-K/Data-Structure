#pragma once 

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef struct DListNode{
    int data;
    struct DListNode* prev;
    struct DListNode* next;
}   DListNode;

// 初始化
void DListInit(DListNode** ppHead);

// 销毁(包括头节点)
void DListDestroy(DListNode** ppHead);

void DListInsert(DListNode* pHead, DListNode* pos, int data);

void DListPushFront(DListNode* pHead, int data);

void DListPushBack(DListNode* pHead, int data);

void DListErase(DListNode* pHead, DListNode* pos);

void DListPopFront(DListNode* pHead);

void DListPopBack(DListNode* pHead);

void DListClear(DListNode** ppHead);

