#pragma once

// 不带头节点的单链表

typedef int SDataType;

// 节点结构
typedef struct SListNode {
	SDataType _data;		// 节点中保存元素
	struct SListNode* _pNext;	// 保存指向下一个节点的地址，节点的类型都是一样的，保存要他指向下一个节点的地址，这个地址的类型就是 Node*
}Node;	// 这个 Node 就是单链表的节点

// 下面给出的是链表的结构，怎样把一个链表记录下来呢？用指针将第一个节点的地址记录下来就可以了
// 给一个链表目的是为了实现简单，在整个过程中没有传二级指针，不给这个结构也可以。
typedef struct SList {
	Node* _pHead;
}SList;

// 初始化
void SListInit(SList* pl);

// 尾插
void SListPushBack(SList* pl, SDataType data);

// 尾删
void SListPopBack(SList* pl);

// 头插
void SListPushFront(SList* pl, SDataType data);

// 头删
void SListPopFront(SList* pl);

// 任意位置插入
void SListInsertAfter(Node* pos, SDataType data);

// 任意位置删除
void SListErase(SList* pl, Node* pos);

Node* SListFind(SList* pl, SDataType data);

// 获取链表中有效节点的个数
int SListSize(SList* pl);

// 查看当前链表是否为空
int SListEmpty(SList* pl);

// 获取第一个节点
Node* SListFront(SList* pl);

// 获取最后一个节点
Node* SListBack(SList* pl);

//
void SListRemove(SList* pl, SDataType data);

//
void SListRemoveAll(SList* pl, SDataType data);

// 销毁
void SListDestroy(SList* pl);


///////////////////////////////////////////
void TestSList();

// 链表没有SList结构，只有Node结构
void SListPushBackII(Node** pHead, SDataType data);

void SListPushFrontII(Node** pHead, SDataType data);

// 带头节点
void SListPushFrontIII(Node* pHead, SDataType data);
