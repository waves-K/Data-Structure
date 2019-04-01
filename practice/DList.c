#pragma once 

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int DataType;

typedef struct DListNode{
    DataType data;
    struct DListNode* prev;
    struct DListNode* next;
}   DListNode;

// 初始化
void DListInit(DListNode** ppHead){
    // 这里 ppHead 指向的是 pHead 这个指针，由于 pHead 是指针，所以不能为空
    assert(ppHead != NULL);

    // 开辟结点空间
    DListNode* pHead = (DListNode*)malloc(sizeof(DListNode));

    // 因为是初始化，所以让头结点的前驱和后继都指向自己
    pHead->prev = pHead;
    pHead->next = pHead;

    // 把头结点的地址赋给链表
    *ppHead = pHead;
}


// 再结点前面插入
void DListInsert(DListNode* pHead, DListNode* pos, DataType data){
    assert(pHead);

    (void)pHead;    // 强转，没用，目的是避免编译器警告
    DListNode* Node = (DListNode*)malloc(sizeof(DListNode));
    Node->data = data;

    Node->prev = pos->prev;
    Node->next = pos;
    pos->prev->next = Node;
    pos ->prev = Node;
}


void DListPushFront(DListNode* pHead, DataType data){
    assert(pHead);
    
    // 头插 就相当于是在头结点的 next 插入
    DListInsert(pHead, pHead->next, data);
}


void DListPushBack(DListNode* pHead, DataType data){
    assert(pHead);

    // 尾插就相当于是在头结点的前驱插入
    DListInsert(pHead, pHead->prev, data);
}


// 任意位置删除结点  
// 注意:这里的 pos 一定不是头结点
void DListErase(DListNode* pHead, DListNode* pos){
    assert(pHead);
    (void)pHead;

    // 被删除的结点一定不能是头结点 pHead 
    assert(pos != pHead);

    pos->next->prev = pos->prev;
    pos->prev->next = pos->next;

    // 记住删完结点之后一定要释放结点的空间
    free(pos);
}


void DListPopFront(DListNode* pHead){
    // 头删就相当于是删除头结点的 next 
    DListErase(pHead, pHead->next);
}


void DListPopBack(DListNode* pHead){
    // 尾删就相当于是删除头结点的 prev 
    DListErase(pHead, pHead->prev);
}


// 清除所有结点
void DListClear(DListNode* pHead){

    DListNode* cur = pHead->next;
    DListNode* next;

    while(cur != pHead){
        next = cur->next;
        free(cur);
    }

    // 此时 cur == pHead,也就是说此时链表中只剩头结点了 
    pHead->next = pHead;
    pHead->prev = pHead;
}


void DListDestroy(DListNode** ppHead){
    DListClear(*ppHead);
    free(*ppHead);
    *ppHead == NULL;
}
