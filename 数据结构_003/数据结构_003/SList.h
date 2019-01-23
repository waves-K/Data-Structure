#pragma once

// ����ͷ�ڵ�ĵ�����

typedef int SDataType;

// �ڵ�ṹ
typedef struct SListNode {
	SDataType _data;		// �ڵ��б���Ԫ��
	struct SListNode* _pNext;	// ����ָ����һ���ڵ�ĵ�ַ���ڵ�����Ͷ���һ���ģ�����Ҫ��ָ����һ���ڵ�ĵ�ַ�������ַ�����;��� Node*
}Node;	// ��� Node ���ǵ�����Ľڵ�

// ���������������Ľṹ��������һ�������¼�����أ���ָ�뽫��һ���ڵ�ĵ�ַ��¼�����Ϳ�����
// ��һ������Ŀ����Ϊ��ʵ�ּ򵥣�������������û�д�����ָ�룬��������ṹҲ���ԡ�
typedef struct SList {
	Node* _pHead;
}SList;

// ��ʼ��
void SListInit(SList* pl);

// β��
void SListPushBack(SList* pl, SDataType data);

// βɾ
void SListPopBack(SList* pl);

// ͷ��
void SListPushFront(SList* pl, SDataType data);

// ͷɾ
void SListPopFront(SList* pl);

// ����λ�ò���
void SListInsertAfter(Node* pos, SDataType data);

// ����λ��ɾ��
void SListErase(SList* pl, Node* pos);

Node* SListFind(SList* pl, SDataType data);

// ��ȡ��������Ч�ڵ�ĸ���
int SListSize(SList* pl);

// �鿴��ǰ�����Ƿ�Ϊ��
int SListEmpty(SList* pl);

// ��ȡ��һ���ڵ�
Node* SListFront(SList* pl);

// ��ȡ���һ���ڵ�
Node* SListBack(SList* pl);

//
void SListRemove(SList* pl, SDataType data);

//
void SListRemoveAll(SList* pl, SDataType data);

// ����
void SListDestroy(SList* pl);


///////////////////////////////////////////
void TestSList();

// ����û��SList�ṹ��ֻ��Node�ṹ
void SListPushBackII(Node** pHead, SDataType data);

void SListPushFrontII(Node** pHead, SDataType data);

// ��ͷ�ڵ�
void SListPushFrontIII(Node* pHead, SDataType data);
