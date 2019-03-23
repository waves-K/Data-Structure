#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>


typedef int SListDataType;

// 链表中的一个节点
typedef struct Node{
    SListDataType value;    // 值
    struct Node *next;      // 下一个节点的地址
} Node;

// Single List 
typedef struct SList{
    Node *first;    // *head; 第一个节点的地址
} SList;

// 初始化 / 销毁
void SListInit(SList *slist);

void SListDestory(SList *slist);
// 增 / 删 / 查 / 改
// 头插
void SListPushFront(SList *slist, SListDataType data);

// 尾插
void SListPushBack(SList *slist, SListDataType data);

// 头删
void SListPopFront(SList *slist);

// 尾删
void SListPopBack(SList *slist);

// 查找，只能遍历查找  时间复杂度O(n)
Node *SListFind(SList *slist, SListDataType data);

// 在 pos 结点的后面插入一个节点
void SListInsertAfter(SList *slist, Node *pos, SListDataType data);

// 在 pos 结点的后面删除一个节点
void SListEraseAfter(SList *slist, Node *pos);

// 删除第一个结点值为 data 的结点
void SListRemove(SList *slist, SListDataType data);

// 删除所有值为 data 的结点
void SListRemoveAll(SList *slist, SListDataType data);



//////////////////////////////////////
// 测试专用打印函数
//////////////////////////////////////
void SListPrint(SList *slist);
