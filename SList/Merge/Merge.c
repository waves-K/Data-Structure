// 合并两个有序单链表，合并后链表荏苒有序

#include<stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    // 其中一个链表为空的情况，会导致 last == NULL 
    if(l1 == NULL){
        return l2;
    }

    if(l2 == NULL){
        return l1;
    }

    // 两个链表都不为空的情况
    struct ListNode* cur1 = l1;     // 指向 l1 的头结点的指针
    struct ListNode* cur2 = l2;     // 指向 l2 的头结点的指针
    struct ListNode* result = NULL; // 结果链表的第一个结点
    struct ListNode* last = NULL;   // 结果链表的最后一个结点

    // 分别用两个指针遍历两个链表 l1 和 l2
    while(cur1 != NULL && cur2 != NULL){
        if(cur1->val <= cur2->val){
            if(result == NULL){
                result = last = cur1;
            }
            else{
                last->next = cur1;
                last = cur1;           
            }
            cur1 = cur1->next;
        }
        else{
            if(result == NULL){
                result = last = cur2;
            }
            else{
                last->next = cur2;
                last = cur2;
            }
            cur2 = cur2->next;
        }
    }
    if(cur1 != NULL){
        last->next = cur1;
    }
    if(cur2 != NULL){
        last->next = cur2;
    }
    return result;
}


int main(){

    return 0;
}
