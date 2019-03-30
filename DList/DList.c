#include"DList.h"

void DListInit(DListNode** ppHead){
    assert(ppHead != NULL);

    DListNode* pHead = (DListNode*)malloc(sizeof(DListNode));
    // 有些情况下，可以把头结点的 data 存一些有效的信息(长度)
    pHead->next = pHead;
    pHead->prev = pHead;

    *ppHead = pHead;
}


void DListInsert(DListNode* pHead, DListNode* pos, int data){
    assert(pHead);
    (void)pHead;    // 这里是强转，其实没有用，目的是防止编译器警告
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    node->data = data;

    node->prev = pos->prev;
    node->next = pos;
    pos->prev->next = node;
    pos->prev = node;
}


void DListPushFront(DListNode* pHead, int data){
    assert(pHead);

    DListInsert(pHead, pHead->next, data);
}


void DListPushBack(DListNode* pHead, int data){
    assert(pHead);

    DListInsert(pHead, pHead, data);
}


void DListErase(DListNode* pHead, DListNode* pos){
    assert(pHead);
    (void)pHead;
    // 这里 pos 一定不是头结点
    assert(pos != pHead);

    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;

    free(pos);
}

void DListPopFront(DListNode* pHead){
    assert(pHead);

    // 链表为空，pHead->next == pHead;
    DListErase(pHead, pHead->next);
}


void DListPopBack(DListNode* pHead){
    assert(pHead);

    DListErase(pHead, pHead->prev);
}


void DListClear(DListNode* pHead){
    assert(pHead);

    DListNode* cur = pHead->next;
    DListNode* next;

    while(cur != pHead){
        next = cur->next;
        free(cur);
    }
    pHead->next = pHead;
    pHead->prev = pHead;
}


void DListDestroy(DListNode** ppHead){
    assert(ppHead != NULL);

    DListClear(*ppHead);
    *ppHead = NULL;
}
