// 判断链表是否带环
// 快慢指针

#include<stdlib.h>
#include<stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;
struct ListNode* detectCycle(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }
    
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while(1){
        fast = fast->next;
        if(fast == NULL){
            return NULL;
        }
        fast = fast->next;
        if (fast == NULL){
            return NULL;
        }
        slow = slow->next;
        if(fast == slow){
            break;
        }
    }
    // 环的入口点
     struct ListNode* n1 = head;
     struct ListNode* n2 = slow;

     while(n1 != n2){
         n1 = n1->next;
         n2 = n2->next;
     }
    
     return n1;
}

int main(){
    return 0;
}
