// 反转一个单链表

#include<stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* result = NULL;
    struct ListNode* node = head;

    while(node != NULL){
        ListNode* next = node->next;

        next->next = result;
        result = node;

        node = next;
    }
    return result;
}



int main(){
    return 0;
}
