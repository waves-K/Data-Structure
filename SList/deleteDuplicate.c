// 删除重复结点，不保留
// 在一个排序链表中，存在重复的结点，删除改链表中重复的结点，重复的结点不保留
// 返回链表的头指针。


// 思路:
// 三个指针:
// 


#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

ListNode* deleteDuplication(ListNode* pHead){
    // 1. 链表为空
    if(pHead == NULL){
        return NULL;
    }

    ListNode* fake = (ListNode*)malloc(sizeof(ListNode));
    fake->next = pHead;

    ListNode* prev = fake;
    ListNode* p1 = pHead;
    ListNode* p2 = pHead->next;

    while(p2 != NULL){
        if(p1->val != p2->val){
            prev = p1;
            p1 = p2;
            p2 = p2->next;
        }
        else{
            while(p2->val == p1->val && p2 != NULL){
                p2 = p2->next;
            }
            ListNode* cur = p1;
            while(cur != NULL){
                ListNode* next = cur->next;
                free(cur);
                cur = next;
            }
            prev->next = p2;
        }
        pHead = fake->next;
        free(fake);
    }
    return fake->next;
}
