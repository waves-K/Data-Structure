// ��תһ��������
// ���룺1->2->3->4->5->NULL
// �����5->4->3->2->1->NULL
// ��ʾ�������õ�����ݹ鷴ת����

#include<stdio.h>

 //Definition for singly-linked list.
 struct ListNode{
	 int val;
	 struct ListNode *next;
 };

 // ����һ��������ָ��
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


// ����������ԭ�����е�ÿһ���ڵ�ͷ�嵽��������
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


// 2. ɾ�������е��ڸ���ֵ val �����нڵ�
// ʾ����1->2->6->3->4->5->6, val = 6
//		�����1->2->3->4->5
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


// 3. ����һ������ͷͷ�ڵ� head �ķǿ���������������м�ڵ㡣����������м��㣬�򷵻صڶ����м���
// Ҫ��ֻ�ܱ���һ������
// ˼·��������ָ��pFast��pSlow������pFastһ���ƶ�������㣬pSlowһ���ƶ�һ���ڵ�
// ���һ�������н�����Ϊ����������β��־��pFast->next == NULL;
// ������������н�����Ϊż��������β��־��pFast == NULL;

// ��������н�����Ϊż������Ҫ�󷵻������м����е�ǰһ���ڵ㣬���ڸ�һ��ָ��pPreSlow����������pSlow��ǰһ���ڵ�
typedef struct ListNode Node;
struct ListNode* middleNode(struct ListNode* head) {
	Node* pFast = head;	// ÿ��������
	Node* pSlow = head;	// ÿ����һ��

	while (pFast && pFast->next) {	
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}

	return pSlow;
}



// 4. ����һ����������������е�����k�����
/*
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x)��
	val(x), next(NULL) {

	}
};
*/
class Solution {
piulic:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		// �������ĺϷ���
		if (NULL == pListHead || 0 == k) {
			return NULL;
		}

		ListNode* pFast = pListHead;
		ListNode* pSloe = pListHead;

		// �ÿ�ָ������k��
		while (k--) {
			// k������������Ч�ڵ�ĸ���
			if (NULL == pFast) {
				return NULL;
			}

			pFast = pFast->next;
		}

		// �� pSlow �� pFast ͬʱ����ƶ�
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
		// �������ĺϷ���
		if (NULL == pListHead || 0 == k) {
			return NULL;
		}

		ListNode* pFast = pListHead;
		ListNode* pSloe = pListHead;

		// �ÿ�ָ������k��
		while (--k) {
			// k������������Ч�ڵ�ĸ���
			if (NULL == pFast) {
				return NULL;
			}

			pFast = pFast->next;
		}

		// �� pSlow �� pFast ͬʱ����ƶ�
		while (pFast->next) {
			pFast = pFast->next;
			pSlow = pSlow->next;
		}

		return pSlow;
	}
};



// 5. ��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľڵ����ڴ��ڻ����x�Ľڵ�֮ǰ
// ��������ͷ������
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

// �������������ͷ�����������ƣ�
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



// 6. ��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�

