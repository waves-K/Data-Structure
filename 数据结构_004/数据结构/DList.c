#include "DList.h"
#include<malloc.h>
#include<stdio.h>
#include<assert.h>



// 带头节点双向循环链表

DLNode* BuyDListNode(int data) {
	DLNode* pNewNode = (DLNode*)malloc(sizeof(DLNode));
	if (NULL == pNewNode) {
		assert(0);
		return NULL;
	}

	pNewNode->_pNext = NULL;
	pNewNode->_pPre = NULL;
	pNewNode->_data = data;

	return pNewNode;
}

// 初始化，链表中至少有一个节点---头节点
void DListInit(DLNode** pHead) {
	assert(pHead);
	*pHead = BuyDListNode(0);		// 先给一个节点，把它当成头节点，将来让pHead指向头节点
								// 此时说明链表中一个有效节点都没有
	(*pHead)->_pNext = *pHead;
	(*pHead)->_pPre = *pHead;
}

// pHead: 链表的地址
void DListPushBack(DLNode* pHead, DLDataType data) {
	DLNode* pNewNode = NULL;
	assert(pHead);

	pNewNode = BuyDListNode(data);

	// 不破坏链表的结构，将新节点链接到链表
	pNewNode->_pNext = pHead;
	pNewNode->_pPre = pHead->_pPre;

	// 在破坏链表的结构
	pHead->_pPre = pNewNode;
	pNewNode->_pPre->_pNext = pNewNode;
}

// 多想--->多画图--->步骤
void DListPopBack(DLNode* pHead) {
	DLNode* pDelNode;
	assert(pHead);	// 链表是否存在（pHead代表头节点）
	// pHead中的值一定不为空，因为pHead中存放的是头指针的地址

	// 1. 空链表
	if (pHead == pHead->_pNext) {
		return;
	}

	// 2. 链表中有节点
	pDelNode = pHead->_pPre;
	pDelNode->_pPre->_pNext = pHead;
	pHead->_pPre = pDelNode->_pPre;

	free(pDelNode);
}

void DListPushFront(DLNode* pHead, DLDataType data) {
	DLNode* pNewNode = NULL;
	assert(pHead);

	pNewNode = BuyDListNode(data);

	// 不破坏链表的结构，将新节点连接到链表中
	pNewNode->_pNext = pHead->_pNext;
	pNewNode->_pPre = pHead;

	// 改变链表的结构
	pHead->_pNext = pNewNode;
	pNewNode->_pNext->_pPre = pNewNode;

}

void DListPopFront(DLNode* pHead) {
	DLNode* pDelNode = NULL;
	assert(pHead);
	if (pHead->_pNext == pHead) {
		return;
	}

	pDelNode = pHead->_pNext;
	pHead->_pNext = pDelNode->_pNext;
	pDelNode->_pNext->_pPre = pHead;

	free(pDelNode);
}

DLNode* DListFind(DLNode* pHead, DLDataType data) {
	DLNode* pCur = NULL;
	assert(pHead);

	pCur = pHead->_pNext;
	while (pCur != pHead) {
		if (pCur->_data == data) {
			return pCur;
		}

		pCur = pCur->_pNext;
	}

	return NULL;
}

void DListInsert(DLNode* pos, DLDataType data) {
	DLNode* pNewNode = NULL;
	if (NULL == pos) {
		return;
	}

	pNewNode = BuyDListNode(data);

	pNewNode->_pNext = pos;
	pNewNode->_pPre = pos->_pPre;
	pos->_pPre = pNewNode;
	pNewNode->_pPre->_pNext = pNewNode;
}

void DListErase(DLNode* pos) {
	if (NULL == pos) {
		return;
	}

	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;

	free(pos);
}

// 将链表中有效节点全部清理
void DListClear(DLNode* pHead) {
	DLNode* pCur = NULL;
	assert(pHead);

	// head 1--->2--->3--->4--->head
	pCur = pHead->_pNext;
	while (pCur != pHead) {
		pHead->_pNext = pCur->_pNext;
		free(pCur);
		pCur = pHead->_pNext;
	}

	pHead->_pNext = pHead;
	pHead->_pPre = pHead;
}

void DListDestroy(DLNode** pHead) {
	DListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}

//////////////////////////////////////////////////
//
void PrintDList(DLNode* pHead) {
	DLNode* pCure = NULL;
	assert(pHead);
	pCure = pHead->_pNext;

	while (pCure != pHead) {
		printf("%d ", pCure->_data);
		pCure = pCure->_pNext;
	}
}

void TestDList1() {
	DLNode* pHead = NULL;
	DListInit(&pHead);

	// 尾插测试
	DListPushBack(pHead, 1);
	DListPushBack(pHead, 2);
	DListPushBack(pHead, 3);
	DListPushBack(pHead, 4);
	DListPushBack(pHead, 5);

	PrintDList(pHead);
	DListDestroy(&pHead);
	// 尾删测试
	DListPopBack(pHead);
	PrintDList(pHead);

	DListPopBack(pHead);
	DListPopBack(pHead);
	DListPopBack(pHead);
	PrintDList(pHead);

	DListPopBack(pHead);
	PrintDList(pHead);

	DListPopBack(pHead);
	DListPopBack(pHead);

	DListDestroy(&pHead);
}

void TestDList2() {
	DLNode* pHead = NULL;
	DListInit(&pHead);

	// 头插测试
	DListPushFront(pHead, 1);
	DListPushFront(pHead, 2);
	DListPushFront(pHead, 3);
	DListPushFront(pHead, 4);
	DListPushFront(pHead, 5);

	PrintDList(pHead);
	DListDestroy(&pHead);

	DListPopFront(pHead);
	PrintDList(pHead);

	DListPopFront(pHead);
	DListPopFront(pHead);
	DListPopFront(pHead);
	PrintDList(pHead);

	DListPopFront(pHead);
	DListPopFront(pHead);
	PrintDList(pHead);
	DListDestroy(&pHead);
}

void TestDList() {
	//TestDList1();
	TestDList2();
}