// 反转一个单链表
// 输入：1->2->3->4->5->NULL
// 输出：5->4->3->2->1->NULL
// 提示：可以用迭代或递归反转链表

#include<stdio.h>

 //Definition for singly-linked list.
 struct ListNode{
	 int val;
	 struct ListNode *next;
 };

 // 方法一：给三个指针
typedef struct ListNode Node;
struct ListNode*  reversList(struct ListNode* head) {
	Node* pPre = NULL;
	Node* pCur = head;
	Node* pNext = NULL;

	while (pCur) {
		pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}

	return pPre;
}


// 方法二：将原链表中的每一个节点头插到新链表中
typedef struct ListNode Node;
struct ListNode*  reversList(struct ListNode* head) {
	Node* pNewHead = NULL;
	Node* pCur = head;

	while (pCur) {
		head = pCur->next;
		pCur->next = pNewHead;
		pNewHead = pCur;
		pCur = head;
	}

	return pNewHead;
}


// 2. 删除链表中等于给定值 val 的所有节点
// 示例：1->2->6->3->4->5->6, val = 6
//		输出：1->2->3->4->5
//


typedef struct ListNode Node;
struct ListNode* removeElements(struct ListNode* head, int val) {
	Node* pCur = head;
	Node* pPre = NULL;

	while (pCur) {
		if (pCur->val == val) {
			if (pCur == head) {
				head = pCur->next;
				free(pCur);
				pCur = head;
			}
			else {
				pPre->next = pCur->next;
				free(pCur);
				pCur = pPre->next;
			}
		}
		else {
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	return head;
}


// 3. 给定一个带有头头节点 head 的非空链表，返回链表的中间节点。如果有两个中间结点，则返回第二个中间结点
// 要求：只能遍历一次链表
// 思路：给两个指针pFast和pSlow，其中pFast一次移动两个结点，pSlow一次移动一个节点
// 情况一：链表中结点个数为奇数个，结尾标志：pFast->next == NULL;
// 情况二：链表中结点个数为偶数个，结尾标志：pFast == NULL;

// 如果链表中结点个数为偶数个，要求返回两个中间结点中的前一个节点，则在给一个指针pPreSlow，用来保存pSlow的前一个节点
typedef struct ListNode Node;
struct ListNode* middleNode(struct ListNode* head) {
	Node* pFast = head;	// 每次走两步
	Node* pSlow = head;	// 每次走一步

	while (pFast && pFast->next) {	
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}

	return pSlow;
}



// 4. 输入一个链表，输出该链表中倒数第k个结点
/*
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x)：
	val(x), next(NULL) {

	}
};
*/
class Solution {
piulic:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		// 检测参数的合法性
		if (NULL == pListHead || 0 == k) {
			return NULL;
		}

		ListNode* pFast = pListHead;
		ListNode* pSloe = pListHead;

		// 让快指针先走k步
		while (k--) {
			// k大于链表中有效节点的个数
			if (NULL == pFast) {
				return NULL;
			}

			pFast = pFast->next;
		}

		// 让 pSlow 和 pFast 同时向后移动
		while (pFast) {
			pFast = pFast->next;
			pSlow = pSlow->next;
		}

		return pSlow;
	}
};


class Solution {
piulic:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		// 检测参数的合法性
		if (NULL == pListHead || 0 == k) {
			return NULL;
		}

		ListNode* pFast = pListHead;
		ListNode* pSloe = pListHead;

		// 让快指针先走k步
		while (--k) {
			// k大于链表中有效节点的个数
			if (NULL == pFast) {
				return NULL;
			}

			pFast = pFast->next;
		}

		// 让 pSlow 和 pFast 同时向后移动
		while (pFast->next) {
			pFast = pFast->next;
			pSlow = pSlow->next;
		}

		return pSlow;
	}
};



// 5. 编写代码，以给定值x为基准将链表分割成两部分，所有小于x的节点排在大于或等于x的节点之前
// 给两个带头的链表
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		if (NULL == pHead || NULL == pHead->next) {
			return NULL;
		}

		ListNode* pCur = pHead;
		ListNode lessHead(0);
		ListNode* pLessTail = &lessHead;

		ListNode greaterHead;
		ListNode* pGreaterTail = &greaterHead;

		while (pCur) {
			if (pCur->val < x) {
				pLessTail->next = pCur;
				pLessTail = pLessTail->next;
			}
			else {
				pGreaterTail->next = pCur;
				pGreaterTail = pGreaterTail->next;
			}

			pCur = pCur->next;
		}
		pLessTail->next = greaterTail.next;
		pGreaterTail->next = NULL;
		return lessHead.next;
	}
};

// 如果是两个不带头的链表（不完善）
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		if (NULL == pHead || NULL == pHead->next) {
			return NULL;
		}

		ListNode* pCur = pHead;
		ListNode* plessHead(0);
		ListNode* pLessTail = NULL;

		ListNode* pGreaterHead = NULL;
		ListNode* pGreaterTail =(0);

		while (pCur) {
			if (pCur->val < x) {
				pLessTail->next = pCur;
				pLessTail = pLessTail->next;
			}
			else {
				pGreaterTail->next = pCur;
				pGreaterTail = pGreaterTail->next;
			}

			pCur = pCur->next;
		}
		pLessTail->next = greaterTail.next;
		pGreaterTail->next = NULL;
		return lessHead.next;
	}
};



// 6. 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的

