

#include<stdlib.h>
#include<stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

struct ListNode* removeElements(struct ListNode* head, int val){
    ListNode* result = NULL;
    ListNode* last = NULL;
    ListNode* cur = head;

    while(cur != NULL){
        if(cur->val != val){
            if(result == NULL){
                result = last = cur;
            }
            else{
                last->next = cur;
                last = cur;
            }
            cur = cur->next;
        }
        else{
            cur = cur->next;
        }
    }

    if(result->val == val){
       ListNode* second = result->next;

       free(result);
       result = second;
    }
    return result;
}

int main(){
    return 0;
}
