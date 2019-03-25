// 删除链表结点中第一个值为 val 的结点

#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

struct ListNode* RemoveElements(struct ListNode* head, int val){
    // 1.先确认第一个结点的值是不是 val
    // 如果是：头删     
    // 如果不是：继续
    
    // 2.用一个指针遍历链表的结点，
    // 指针的含义：确认指针指向的下一个节点保存的值是不是 val
    // 指针的符号：cur
    // 指针的范围：[first, 倒数第二个结点]
    
    // 3.如果找到了，进行删除
    // cur->next = cur->next->next
    // 释放原来的结点: free(cur->next)
    
    // 链表中一个结点都没有的情况
    if(head == NULL){
        return NULL;
    }

    // 链表中有节点的情况
    if(head->val == val){
        // 头删，记录原来链表的第二个结点
        ListNode* second = head->next;
        free(head);
        head->next = second;
    }
    else{
        ListNode* cur = head;
        while(cur->next != NULL){
            if(cur->next->val == val){
                ListNode* next = cur->next;
                cur->next = next->next;
                free(next);
                break;
            }
            cur = cur->next;
        }
    }
    return head;
}


int main(){
    return 0;
}
