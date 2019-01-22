#include "SList.h"
#include<assert.h>
#include<stdio.h>
#include<malloc.h>

// ��ʼ����˵��������һ����ЧԪ�ض�û�У������� pl->_pHead ָ���
void SListInit(SList* pl) {
	assert(pl);
	pl->_pHead = NULL;
}

// β��
// ���� 1. ����һ���ڵ㣬����ڵ���������������һ������������Ԫ�صģ�����һ��������ָ����һ���ڵ�ģ�������β�壬������һ���ڵ����NULL
//		2. Ҫ����β�����������Ҫ�ҵ���������һ��Ԫ�أ���ʱֻ�ܴ�ͷ�����ң�ֻҪ���ھ�ȡnext,ֻҪnextΪ�վ�˵������û�нڵ��ˣ���ʱ��Ϊ�յ�nextָ��β����Ǹ�Ԫ�� 

// �����ڵ㣬�����еĽڵ㣬�����϶��ǴӶ���Ū�ģ�����ڵ��н������data�������
Node* BuySListNode(SDataType data) {
	// �ڶ��Ͽ���һ���ڵ�Ŀռ䣬���Ҫ���ٽڵ�Ŀռ䣬malloc��ߵ�sizeof��߷ŵ�һ����Node��
	// ��ΪҪһ���ڵ���ǰ�����ڵ��еĴ�С������ȥ���м����ﲻҪ��������Node*������Ҫ���ǽڵ㣬���ǽڵ����͵�ָ��
	Node* pNode = (Node*)malloc(sizeof(Node));
	// �жϽڵ��Ƿ񴴽���ȷ
	if (NULL == pNode) {
		assert(0);
		return NULL;
	}

	// �����ýڵ��Ͷ�����ڵ��е����ݳ�ʼ��
	pNode->_data = data;	// ��ʼ��ֵ��
	pNode->_pNext = NULL;	// ��ʼ��ָ����

	return pNode;	// ���ؽڵ�
}

void SListPushBack(SList* pl, SDataType data) {
	Node* pNewNode = NULL;	// �½ڵ�
	Node* pCur = NULL;		// ���������е����һ���ڵ�

	assert(pl);
	
	// ������ڣ������½ڵ�
	pNewNode = BuySListNode(data);
	pCur = pl->_pHead;

	// �������������������
	if (NULL == pl->_pHead) {
		pl->_pHead = pNewNode;
	}
	else {
		while (pCur->_pNext) {
			pCur = pCur->_pNext;
		}

		// �����½ڵ�
		pCur->_pNext = pNewNode;
	}
}

void SListPopBack(SList* pl) {
	assert(pl);
	if (NULL == pl->_pHead) {	// ������
		return;
	}

	// ������ֻ��һ���ڵ㣬�ж���������һ���ڵ��next��Ϊ��
	else if (NULL == pl->_pHead->_pNext) {
		free(pl->_pHead);	// ɾ����һ���ڵ�
		pl->_pHead = NULL;	// ɾ��֮����Head�ÿ�
	}

	else {	// �����������ڵ�

		/*
		// ����һ���ҵ�����һ���ڵ㣬��������ǰһ���ڵ�
		Node* pTailNode = pl->_pHead;	// �ҵ�β�ڵ�
		Node* pPreTail = NULL;		// �����һ���ڵ��ǰһ���ڵ��ÿ�

		// ���һ���ڵ�ı�־��������NextΪ��
		while (pTailNode->_pNext) {
			pPreTail = pTailNode;	// ��pTailNode�������һ���ڵ�ʱ��ʹ��pPreTail���pTailNode
			pTailNode = pTailNode->_pNext;
		}

		free(pTailNode);
		pPreTail->_pNext = NULL;
		*/

		// ���������ҵ����ڶ����ڵ�
		Node* pTailNode = pl->_pHead;
		while (pTailNode->_pNext->_pNext) {
			pTailNode = pTailNode->_pNext;
		}

		free(pTailNode->_pNext);
		pTailNode->_pNext = NULL;
	}
}

// ͷ��
void SListPushFront(SList* pl, SDataType data) {
	Node* pNewNode = NULL;	// �����½ڵ�
	assert(pl);

	pNewNode = BuySListNode(data);	// ����Ԫ��
	pNewNode->_pNext = pl->_pHead;	// ����ԭ����ָ��ԭ�����ͷ�ڵ�
	pl->_pHead = pNewNode;	// ����ͷ�ڵ�
}

// ͷɾ
void SListPopFront(SList* pl) {
	assert(pl);
	// ���һ��������
	if (NULL == pl->_pHead) {
		return;
	}

	// ��������ǿ�����
	else {
		Node* pDelNode = pl->_pHead;	// ��¼Ҫɾ���Ľڵ㣬������ĵ�һ���ڵ�
		pl->_pHead = pDelNode->_pNext;	// ��Ҫɾ���ڵ��nextָ��Head
		free(pDelNode);
	}
}

// ����λ�ò���
//	  ��ʱ���뱣֤ pos ��Ϊ�գ������޷�����
void SListInsertAfter(Node* pos, SDataType data) {
	Node* pNewNode = NULL;	// �����½ڵ�
	// ע�⣺���ﲻ����ֱ�ӹ���ڵ㣬�磺Node* pNewNode = BuySListNode(data)
	//      ���ֱ�ӹ���ڵ�Ļ��ͻᵼ�� pos ����⣬��ʱ�������Ϊ�գ��ͻ�ֱ�ӷ���
	//		������½ڵ�Ͳ��ܱ��ͷţ���ɿռ�й¶�������ٹ����½ڵ�ʱ�����ÿ�
	if (NULL == pos) {
		return;
	}
	
	pNewNode = BuySListNode(data);
	// ע�⣺���Ľڵ�����ʱ��Ҫ�ƻ�ԭ����Ľṹ
	pNewNode->_pNext = pos->_pNext;		// ��һ�������½ڵ���posָ��Ľڵ�����
	pos->_pNext = pNewNode;		// �ڶ�������pos���½ڵ�����
}

// ����λ��ɾ��
void SListErase(SList* pl, Node* pos) {
	Node* pPrePos = NULL;	// �ҵ�Ҫɾ���ڵ��ǰһ���ڵ�
	assert(pl);
	if (NULL == pl->_pHead || NULL == pos) {
		return;
	}

	// pos�պ��ڵ�һ���ڵ��λ��
	if (pos = pl->_pHead) {
		pl->_pHead = pos->_pNext;
		free(pos);
		return;
	}

	// pos�ڷǵ�һ���ڵ��λ��
	pPrePos = pl->_pHead;
	while (pPrePos->_pNext != pos) {
		pPrePos = pPrePos->_pNext;
	}

	pPrePos->_pNext = pos->_pNext;

	free(pos);
}

Node* SListFind(SList* pl, SDataType data) {
	Node* pCur = pl->_pHead;	// ��ͷ����ʼ���ҽڵ�λ��
	assert(pl);

	while (pCur) {
		// ����ڵ���ڣ����жϵ�ǰ�ڵ㱣��������ǲ�������Ҫ��data
		if (pCur->_data == data) {
			return pCur;
		}

		pCur = pCur->_pNext;
	}

	return NULL;
}

int SListSize(SList* pl) {
	Node* pCur = NULL;
	int count = 0;
	assert(pl);

	pCur = pl->_pHead;
	while (pCur) {
		count++;
		pCur = pCur->_pNext;
	}

	return count;
}

int SListEmpty(SList* pl) {
	assert(pl);
	return NULL == pl->_pHead;
}

// ��ȡ��һ���ڵ�
Node* SListFront(SList* pl) {
	assert(pl);
	return pl->_pHead;
}

// ��ȡ���һ���ڵ㣬���뱣֤��β�ڵ�
Node* SListBack(SList* pl) {
	Node* pCur = NULL;
	assert(pl);
	assert(pl->_pHead);

	pCur = pl->_pHead;
	while (pCur->_pNext) {
		pCur = pCur->_pNext;
	}

	return pCur;
}

void SListDestroy(SList* pl) {
	Node* pCur = NULL;
	assert(pl);

	// ��ͷ����ʼ����
	pCur = pl->_pHead;
	while (pCur) {
		pl->_pHead = pCur->_pNext;
		free(pCur);
		pCur = pl->_pHead;
	}

	// �ͷ���֮����� pl->_pHeadָ���
	pl->_pHead = NULL;
}



////////////////////////////////////////////////
//
void PrintSList(SList* pl) {
	Node* pCur = NULL;
	assert(pl);

	pCur = pl->_pHead;
	while (pCur) {
		printf("%d--->", pCur->_data);
		pCur = pCur->_pNext;
	}

	printf("NULL\n");
}


void TestSList1() {
	// ��������
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	PrintSList(&s);

	SListPopBack(&s);
	PrintSList(&s);
	SListPopBack(&s);
	PrintSList(&s);
	SListPopBack(&s);
	PrintSList(&s);
	SListPopBack(&s);
	PrintSList(&s);

	SListDestroy(&s);
}

void TestSList2() {
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	PrintSList(&s);

	SListPushFront(&s, 0);
	PrintSList(&s);

	SListPopFront(&s);
	PrintSList(&s);

	SListPopFront(&s);
	PrintSList(&s);

	SListPopFront(&s);
	PrintSList(&s);

	SListPopFront(&s);
	PrintSList(&s);

	SListPopFront(&s);
	PrintSList(&s);

	SListDestroy(&s);
}

void TestSList3() {
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	PrintSList(&s);

	SListInsertAfter(SListFind(&s, 2), 5);
	PrintSList(&s);

	SListErase(&s, SListFind(&s, 5));
	PrintSList(&s);

	SListErase(&s, SListFind(&s, 1));
	PrintSList(&s);

	SListDestroy(&s);

}

// 1. ����Ϊ��
// 2. ����ǿ�----�����һ���ڵ�

// pHead ����---����ĵ�ַ������ͷָ��ĵ�ַ
// ����û��SList�ṹ��ֻ��Node�ṹ
void SListPushBackII(Node** pHead, SDataType data) {
	assert(pHead);
	Node* pNewNode = BuySListNode(data);
	if (NULL == *pHead) {
		*pHead = pNewNode;
	}
	else {
		Node* pCur = pHead;
		while (pCur->_pNext) {
			pCur = pCur->_pNext;
		}
		pCur->_pNext = pNewNode;
	}
}

void TestSList4() {
	Node* pHead = NULL;
	SListPushBackII(&pHead, 1);
	PrintSList(&pHead);

	SListDestroy(&pHead);
}
void TestSList() {
	//TestSList1();
	//TestSList2();
	//TestSList3();
	TestSList4();
}