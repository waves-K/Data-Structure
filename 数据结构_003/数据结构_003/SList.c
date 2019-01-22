#include "SList.h"
#include<assert.h>
#include<stdio.h>
#include<malloc.h>

// 初始化，说明链表中一个有效元素都没有，所以让 pl->_pHead 指向空
void SListInit(SList* pl) {
	assert(pl);
	pl->_pHead = NULL;
}

// 尾插
// 操作 1. 构造一个节点，这个节点中有两个域，其中一个是用来保存元素的，另外一个是用来指向下一个节点的，由于是尾插，所以下一个节点就是NULL
//		2. 要进行尾插操作，就需要找到链表的最后一个元素，此时只能从头往后找，只要存在就取next,只要next为空就说明后面没有节点了，此时让为空的next指向尾插的那个元素 

// 创建节点，链表中的节点，基本上都是从堆上弄的，这个节点中将来存放data这个数据
Node* BuySListNode(SDataType data) {
	// 在堆上开辟一个节点的空间，如果要开辟节点的空间，malloc里边的sizeof里边放的一定是Node。
	// 因为要一个节点就是把这个节点中的大小给传过去，切记这里不要把它给成Node*。我们要的是节点，不是节点类型的指针
	Node* pNode = (Node*)malloc(sizeof(Node));
	// 判断节点是否创建正确
	if (NULL == pNode) {
		assert(0);
		return NULL;
	}

	// 创建好节点后就对这个节点中的数据初始化
	pNode->_data = data;	// 初始化值域
	pNode->_pNext = NULL;	// 初始化指针域

	return pNode;	// 返回节点
}

void SListPushBack(SList* pl, SDataType data) {
	Node* pNewNode = NULL;	// 新节点
	Node* pCur = NULL;		// 查找链表中的最后一个节点

	assert(pl);
	
	// 链表存在，给出新节点
	pNewNode = BuySListNode(data);
	pCur = pl->_pHead;

	// 空链表，解决空链表问题
	if (NULL == pl->_pHead) {
		pl->_pHead = pNewNode;
	}
	else {
		while (pCur->_pNext) {
			pCur = pCur->_pNext;
		}

		// 插入新节点
		pCur->_pNext = pNewNode;
	}
}

void SListPopBack(SList* pl) {
	assert(pl);
	if (NULL == pl->_pHead) {	// 空链表
		return;
	}

	// 链表中只有一个节点，判断条件：第一个节点的next就为空
	else if (NULL == pl->_pHead->_pNext) {
		free(pl->_pHead);	// 删除第一个节点
		pl->_pHead = NULL;	// 删除之后让Head置空
	}

	else {	// 至少有两个节点

		/*
		// 方法一：找倒数第一个节点，并保存其前一个节点
		Node* pTailNode = pl->_pHead;	// 找到尾节点
		Node* pPreTail = NULL;		// 将最后一个节点的前一个节点置空

		// 最后一个节点的标志就是它的Next为空
		while (pTailNode->_pNext) {
			pPreTail = pTailNode;	// 当pTailNode不是最后一个节点时，使用pPreTail标记pTailNode
			pTailNode = pTailNode->_pNext;
		}

		free(pTailNode);
		pPreTail->_pNext = NULL;
		*/

		// 方法二：找倒数第二个节点
		Node* pTailNode = pl->_pHead;
		while (pTailNode->_pNext->_pNext) {
			pTailNode = pTailNode->_pNext;
		}

		free(pTailNode->_pNext);
		pTailNode->_pNext = NULL;
	}
}

// 头插
void SListPushFront(SList* pl, SDataType data) {
	Node* pNewNode = NULL;	// 创建新节点
	assert(pl);

	pNewNode = BuySListNode(data);	// 放入元素
	pNewNode->_pNext = pl->_pHead;	// 链接原链表，指向原链表的头节点
	pl->_pHead = pNewNode;	// 更新头节点
}

// 头删
void SListPopFront(SList* pl) {
	assert(pl);
	// 情况一：空链表
	if (NULL == pl->_pHead) {
		return;
	}

	// 情况二：非空链表
	else {
		Node* pDelNode = pl->_pHead;	// 记录要删除的节点，即链表的第一个节点
		pl->_pHead = pDelNode->_pNext;	// 让要删除节点的next指向Head
		free(pDelNode);
	}
}

// 任意位置插入
//	  此时必须保证 pos 不为空，否则无法插入
void SListInsertAfter(Node* pos, SDataType data) {
	Node* pNewNode = NULL;	// 构造新节点
	// 注意：这里不可以直接构造节点，如：Node* pNewNode = BuySListNode(data)
	//      如果直接构造节点的话就会导致 pos 不检测，此时如果链表为空，就会直接返回
	//		构造的新节点就不能被释放，造成空间泄露，所以再构造新节点时把它置空
	if (NULL == pos) {
		return;
	}
	
	pNewNode = BuySListNode(data);
	// 注意：更改节点链接时不要破坏原链表的结构
	pNewNode->_pNext = pos->_pNext;		// 第一步：让新节点与pos指向的节点链接
	pos->_pNext = pNewNode;		// 第二步：让pos与新节点链接
}

// 任意位置删除
void SListErase(SList* pl, Node* pos) {
	Node* pPrePos = NULL;	// 找到要删除节点的前一个节点
	assert(pl);
	if (NULL == pl->_pHead || NULL == pos) {
		return;
	}

	// pos刚好在第一个节点的位置
	if (pos = pl->_pHead) {
		pl->_pHead = pos->_pNext;
		free(pos);
		return;
	}

	// pos在非第一个节点的位置
	pPrePos = pl->_pHead;
	while (pPrePos->_pNext != pos) {
		pPrePos = pPrePos->_pNext;
	}

	pPrePos->_pNext = pos->_pNext;

	free(pos);
}

Node* SListFind(SList* pl, SDataType data) {
	Node* pCur = pl->_pHead;	// 从头部开始查找节点位置
	assert(pl);

	while (pCur) {
		// 如果节点存在，就判断当前节点保存的数据是不是我需要的data
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

// 获取第一个节点
Node* SListFront(SList* pl) {
	assert(pl);
	return pl->_pHead;
}

// 获取最后一个节点，必须保证有尾节点
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

	// 从头部开始销毁
	pCur = pl->_pHead;
	while (pCur) {
		pl->_pHead = pCur->_pNext;
		free(pCur);
		pCur = pl->_pHead;
	}

	// 释放完之后就让 pl->_pHead指向空
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
	// 创建链表
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

// 1. 链表为空
// 2. 链表非空----找最后一个节点

// pHead 含义---链表的地址，不是头指针的地址
// 链表没有SList结构，只有Node结构
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