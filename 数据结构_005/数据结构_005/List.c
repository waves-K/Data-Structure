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
// ���룺1->2->4, 1->3->4
// �����1->1->2->3->4->4

typedef struct ListNode Node;
struct ListNode* mergeTowLists(struct ListNode* l1, struct ListNode* l2) {
	Node* head = NULL;
	Node* p1 = l1;
	Node* p2 = l2;
	Node* pTailNode = NULL;

	if (NULL == l1) {
		return l2;
	}

	if (NULL == l2) {
		return l1;
	}

	if (p1->val <= p2->val) {
		head = p1;
		pTailNode = p1;
		p1 = p1->next;
	}
	else {
		head = p2;
		pTailNode = p2;
		p2 = p2->next;
	}

	while (p1 && p2) {
		if (p1->val <= p2->val) {
			// ��p1�ڵ�β�嵽��������
			pTailNode->next = p1;
			p1 = p1->next;
		}

		else {
			// ��p2�ڵ�β�嵽��������
			pTailNode->next = p2;
			p2 = p2->next;
		}

		pTailNode = pTailNode->next;
	}

	if (p1) {
		pTailNode->next = p1;
	}

	if (p2) {
		pTailNode->next = p2;
	}

	return head;
}

// �򻯴���
typedef struct ListNode Node;
struct ListNode* mergeTowLists(struct ListNode* l1, struct ListNode* l2) {
	Node head;
	Node* p1 = l1;
	Node* p2 = l2;
	Node* pTailNode = &head;

	if (NULL == l1) {
		return l2;
	}

	if (NULL == l2) {
		return l1;
	}

	/*
	if (p1->val <= p2->val) {
		head = p1;
		pTailNode = p1;
		p1 = p1->next;
	}
	else {
		head = p2;
		pTailNode = p2;
		p2 = p2->next;
	}
	*/

	while (p1 && p2) {
		if (p1->val <= p2->val) {
			// ��p1�ڵ�β�嵽��������
			pTailNode->next = p1;
			p1 = p1->next;
		}

		else {
			// ��p2�ڵ�β�嵽��������
			pTailNode->next = p2;
			p2 = p2->next;
		}

		pTailNode = pTailNode->next;
	}

	if (p1) {
		pTailNode->next = p1;
	}

	if (p2) {
		pTailNode->next = p2;
	}

	return head.next;
}



// ����Ļ��Ľṹ��
// ���ģ������м�λ�öԳ�   eg��1221     12321    ������
// ����һ�����������һ��ʱ�临�Ӷ�ΪO(n)������ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
// ����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900.
// ����������1->2->2->1     ���أ�ture

/*
struct ListNode{
	int val;
	struct ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};
*/

/*
class PalondromeList {
public:
	ListNode* ReverseList(ListNode* pHead) {
		LostNode* pNewHead = NULL;
		ListNode* pCur = pHead;
		while (pCur) {
			pHead = pCur->next;
			pCur->next = pNewHead;
			pNewHead = pCur; pCur = pHead;
		}

		return pNewHead;
	}
	bool chkPalindrome(ListNode* A) {

		// ���������������ֻ��һ���ڵ�--->��
		if (NULL == A || NULL == A->next) {
			return ture;
		}

		// �������ж���ڵ�-->
		// ��������м�λ�öϿ����γ���������head1��head2
		// ���ҽ�head2���ã���ǰ�������αȽ������нڵ��Ƿ����

		// �ҵڶ�������ĵ�һ���ڵ�
		ListNode* pFast = A;
		ListNode* pSlow = A;
		Listnode* pPreSlow = NULL;
		while (pFast && pFast->next) {
			pFast = pFast->next->next;
			pPreSlow = pSlow;
			pSlow = pSlow->next;
		}

		pPreSlow->next = NULL;

		// �Եڶ��������������
		ListNode* pHead2 = ReverseList(pSlow);

		ListNode* p1 = A;
		ListNode* p2 = pHead2;

		bool Ret = false;
		while (p1) {
			if (p1->val != p2->val) {
				back;
			}

			p1 = p1->next;
			p2 = p2->next;
		}

		if (NULL == p1) {
			Ret = true;
		}

		pPreSlow->next = ReverseList(pHead2);
		return Ret;
	}
};
*/

// ��㷽��
class PalondromeList {
public:
	bool chkPalindrome(ListNode* A) {
		if (NULL == A || NULL == A->next) {
			return true;
		}

		size_t count = 0;
		int* pTemp = (int*)malloc(sizeof(int) * 900);
		ListNode* pCur = A;
		int count = 0;
		// ��������
		while (pCur) {
			pTemp[count++] = pCur->val;
			pCur = pCur->next;
		}

		bool ret = false
		int begin = 0, end = count - 1;
		while (begin < end) {
			if (pTemp[begin] != pTemp[end]) {
				break;
			}

			begin++;
			end--;
		}

		if (begin >= end) {
			ret = true;
		}

		free(pTemp);

		return ret;
	}

}��




// 9. ��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ��
// ˼·��1. ���ظ���������λ��[first,last��
//		2. ɾ���ظ�����[first,last)�ڵ�Ԫ��




// 10. �������������ҳ����ǵĵ�һ��������㡣�����������ཻ���ӽ���֮��ÿ��Ԫ�ض��ǹ�����㣬�����������ƶ���
/*
Definition for singly-linked list.
struct ListNode{
	int val;
	struct ListNode* next;
};
*/
typedef struct ListNode Node;

Node* Back(Node* pHead) {
	Node* pCur = pHead;
	if (NULL == pHead) {
		return NULL;
	}

	while (pCur->next) {
		pCur = pCur->next;
	}

	return pCur;
}

int Size(Node* pHead) {
	int count = 0;
	Node* pCur = pHead;
	while (pCur) {
		count++;
		pCur = pCur->next;
	}

	return count;
}

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	Node* pCur1 = NULL;
	Node* pCur2 = NULL;
	if (NULL == headA || NULL == headB) {
		return NULL;
	}

	// ������������Ƿ��ཻ
	// ԭ�����������������һ���ڵ�,���Ƿ���ͬ����ͬ���ཻ�������ཻ
	Node* pTail1 = Back(headA);
	Node* pTail2 = Back(headB);
	if (pTail1 != pTail2) {
		return NULL;
	}

	// ȷ���Ǹ�����Ƚϳ�
	/*int size1 = Size(headA);
	int size2 = Size(headB);*/
	int gap = Size(headA) - Size(headB);

	pCur1 = headA;
	pCur2 = headB;

	// �ó�������������ƶ�gap��
	if (gap > 0) {
		while (gap) {
			pCur1 = pCur1->next;
			gap--;
		}
	}
	else {
		while(gap++){
			pCur2 = pCur2->next;
		}
	}
	while (pCur1 != pCur2) {
		pCur1 = pCur1->next;
		pCur2 = pCur2->next;
	}
	return pCur1;
}




// 11. ����һ�������ж��������Ƿ��л�
typedef struct ListNode Node;
bool hasCycle(struct ListNode* head) {
	Node* pFast = head;
	Node* pSlow = head;

	while (pFast && pFast->next) {
		pFast = pFast->next->next;
		pSlow = pSlow->next;

		if (pFast == pSlow) {
			return true;
		}
	}
	return false;
}



// 12. ����һ��������������ʼ�绷�ĵ�һ���ڵ㡣��������޻����򷵻�NULL��
typedef struct ListNode Node;
struct ListNode* detectCycle(struct ListNode* head) {
	Node* pFast = head;
	Node* pSlow = head;

	Node* pM = NULL;
	Node* pH = head;

	while (pFast && pFast->next) {
		pFast = pFast->next->next;
		pSlow = pSlow->next;

		if (pFast == pSlow) {
			pM = pFast;
			break;
		}
	}

	if (NULL == pM) {
		return NULL;
	}

	// ����ڵ�

	while (pH != pM) {
		pH = pH->next;
		pM = pM->next;
	}

	return pM;
}


