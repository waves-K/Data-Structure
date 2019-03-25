// 返回链表的中间结点

// 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
// 如果有两个中间结点，则返回第二个中间结点。

// 思路：快慢指针
// 快指针先，接着慢指针走，然后再快指针走

#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* quick = head;
    struct ListNode* slow = head;

    while(quick != NULL){
        quick = quick->next;
        if(quick == NULL){
            break;
        }
        slow = slow->next;
        quick = quick->next;
    }
    return slow;
}


int main(){
    return 0;
}
