// 复制复杂链表

// 问题点：
// 1.怎样复制 random 字段
// 2.找到 random 在链表中对应的结点的地址
// 3.一次遍历时，新链表还不全

// 如何根据老节点的 random 找到新结点的 random

// 思路:
// 1.遍历整个链表，复制结点，将新结点插入到老结点的后面
// 2.遍历整个链表(老结点)，复制 random 字段 (老结点的 random 的 next)
// 3.将整个链表拆成老链表和新链表

#include<stdio.h>
#include<stdlib.h>


typedef struct CLNode{
    int data;
    struct CLNode* random;
    struct CLNode* next;
}CLNode;

static CLNode* ComplexCreateNode(int data){
    CLNode* node = (CLNode*)malloc(sizeof(CLNode));
    node->data = data;
    node->random = NULL;
    node->next = NULL;
    
    return node;
}
CLNode* Copy(CLNode* list){
    // 1.复制结点
    CLNode* cur = list;
    while(cur != NULL){
        CLNode* newNode = ComplexCreateNode(cur->data);
        newNode->next = cur->next;
        cur->next = newNode;

        // 不能直接 next 
        cur = cur->next->next;
    }
    // 2.复制 random 
    cur = list;     // 循环之前让 cur 从 list 开始
    while(cur != NULL){
        if(cur->random != NULL){
            cur->next->random = cur->random->next;
        }

        cur = cur->next->next;
    }
    
    // 3.拆分
    cur = list;
    CLNode* newList = cur->next;    // 保存新链表
    while(cur != NULL){
        CLNode* node = cur->next;

        cur->next = node->next;
        if(cur->next != NULL){
            node->next = cur->next->next;
        }
        else{
            node->next = NULL;
        }

        // 注意
        cur = cur->next;
    }
    return newList;
}

// 打印函数
void PrintComplexList(CLNode* list){
    for(CLNode* cur = list; cur != NULL; cur = cur->next){
        printf("[%d, random(%p)->%d]", cur->data, cur->random,
                cur->random ? cur->random->data : 0);
    }
    printf("\n");
}


// 测试用例
void TestComplex(){
    CLNode* n1 = ComplexCreateNode(1);
    CLNode* n2 = ComplexCreateNode(2);
    CLNode* n3 = ComplexCreateNode(3);
    CLNode* n4 = ComplexCreateNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    n1->random = n3;
    n2->random = n1;
    n3->random = n3;

    CLNode* newList = Copy(n1);
    PrintComplexList(n1);
    PrintComplexList(newList);
}

int main(){
    TestComplex();
}

