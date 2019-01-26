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
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

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
			// 将p1节点尾插到新链表中
			pTailNode->next = p1;
			p1 = p1->next;
		}

		else {
			// 将p2节点尾插到新链表中
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

// 简化代码
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
			// 将p1节点尾插到新链表中
			pTailNode->next = p1;
			p1 = p1->next;
		}

		else {
			// 将p2节点尾插到新链表中
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



// 链表的回文结构。
// 回文：关于中间位置对称   eg：1221     12321    空链表
// 对于一个链表，请设计一个时间复杂度为O(n)，额外空间复杂度为O(1)的算法，判断其是否为回文结构。
// 给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900.
// 测试样例：1->2->2->1     返回：ture

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

		// 空链表或者链表中只有一个节点--->是
		if (NULL == A || NULL == A->next) {
			return ture;
		}

		// 链表中有多个节点-->
		// 将链表从中间位置断开，形成两个链表head1与head2
		// 并且将head2逆置，从前往后依次比较链表中节点是否相等

		// 找第二个链表的第一个节点
		ListNode* pFast = A;
		ListNode* pSlow = A;
		Listnode* pPreSlow = NULL;
		while (pFast && pFast->next) {
			pFast = pFast->next->next;
			pPreSlow = pSlow;
			pSlow = pSlow->next;
		}

		pPreSlow->next = NULL;

		// 对第二个链表进行逆置
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

// 简便方法
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
		// 遍历链表
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

}；




// 9. 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针
// 思路：1. 找重复结点的区间位置[first,last）
//		2. 删除重复区间[first,last)内的元素




// 10. 输入两个链表，找出他们的第一个公共结点。（两个链表相交，从交点之后每个元素都是公共结点，公共结点可以移动）
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

	// 检测两个链表是否相交
	// 原理：找两个链表中最后一个节点,看是否相同，相同就相交，否则不相交
	Node* pTail1 = Back(headA);
	Node* pTail2 = Back(headB);
	if (pTail1 != pTail2) {
		return NULL;
	}

	// 确认那个链表比较长
	/*int size1 = Size(headA);
	int size2 = Size(headB);*/
	int gap = Size(headA) - Size(headB);

	pCur1 = headA;
	pCur2 = headB;

	// 让长的链表先向后移动gap步
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




// 11. 给定一个链表，判断链表中是否有环
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



// 12. 给定一个链表，返回链表开始如环的第一个节点。如果链表无环，则返回NULL；
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

	// 求入口点

	while (pH != pM) {
		pH = pH->next;
		pM = pM->next;
	}

	return pM;
}


