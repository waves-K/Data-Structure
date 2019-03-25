// 分割链表
// 给定值 x 为基准，将链表分割成两部分,所有小于 x 的结点排在 大于或等于 x 的点之前
// 给定一个链表的头指针
// 注意: 分割后保持原来的数据顺序不变

#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

ListNode* partition(ListNode* pHead, int x){
    ListNode* small = NULL;         // 小链表的第一个结点
    ListNode* smallLast = NULL;     // 小链表的最后一个结点

    ListNode* big = NULL;           // 大连表的第一个结点
    ListNode* bigLast = NULL;       // 大链表的最后一个结点

    ListNode* cur = pHead;

    // 遍历链表，将链表分割
    while(cur != NULL){
        if(cur->val < x){
            if(small == NULL){
                small = smallLast = cur;
            }
            else{
                smallLast->next = cur;
                smallLast = cur;
            }
            cur = cur->next;
        }
        else{
            if(big == NULL){
                big = bigLast = cur;
            }
            else{
                bigLast->next = cur;
                bigLast = cur;
            }
            cur = cur->next;
        }
    }

    // 合并分割后的链表
    // 这里需要注意的是小链表为空的情况
    if(small == NULL){
        return big;
    }
    if(big == NULL){
        return small;
    }
    if(small != NULL && big != NULL){
        smallLast->next = big;
    }
    return small;
}


int main(){
    return 0;
}
