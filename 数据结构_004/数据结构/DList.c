#include "DList.h"
#include<malloc.h>
#include<stdio.h>
#include<assert.h>



// ��ͷ�ڵ�˫��ѭ������

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

// ��ʼ����������������һ���ڵ�---ͷ�ڵ�
void DListInit(DLNode** pHead) {
	assert(pHead);
	*pHead = BuyDListNode(0);		// �ȸ�һ���ڵ㣬��������ͷ�ڵ㣬������pHeadָ��ͷ�ڵ�
								// ��ʱ˵��������һ����Ч�ڵ㶼û��
	(*pHead)->_pNext = *pHead;
	(*pHead)->_pPre = *pHead;
}

// pHead: ����ĵ�ַ
void DListPushBack(DLNode* pHead, DLDataType data) {
	DLNode* pNewNode = NULL;
	assert(pHead);

	pNewNode = BuyDListNode(data);

	// ���ƻ�����Ľṹ�����½ڵ����ӵ�����
	pNewNode->_pNext = pHead;
	pNewNode->_pPre = pHead->_pPre;

	// ���ƻ�����Ľṹ
	pHead->_pPre = pNewNode;
	pNewNode->_pPre->_pNext = pNewNode;
}

// ����--->�໭ͼ--->����
void DListPopBack(DLNode* pHead) {
	DLNode* pDelNode;
	assert(pHead);	// �����Ƿ���ڣ�pHead����ͷ�ڵ㣩
	// pHead�е�ֵһ����Ϊ�գ���ΪpHead�д�ŵ���ͷָ��ĵ�ַ

	// 1. ������
	if (pHead == pHead->_pNext) {
		return;
	}

	// 2. �������нڵ�
	pDelNode = pHead->_pPre;
	pDelNode->_pPre->_pNext = pHead;
	pHead->_pPre = pDelNode->_pPre;

	free(pDelNode);
}

void DListPushFront(DLNode* pHead, DLDataType data) {
	DLNode* pNewNode = NULL;
	assert(pHead);

	pNewNode = BuyDListNode(data);

	// ���ƻ�����Ľṹ�����½ڵ����ӵ�������
	pNewNode->_pNext = pHead->_pNext;
	pNewNode->_pPre = pHead;

	// �ı�����Ľṹ
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

// ����������Ч�ڵ�ȫ������
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

	// β�����
	DListPushBack(pHead, 1);
	DListPushBack(pHead, 2);
	DListPushBack(pHead, 3);
	DListPushBack(pHead, 4);
	DListPushBack(pHead, 5);

	PrintDList(pHead);
	DListDestroy(&pHead);
	// βɾ����
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

	// ͷ�����
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