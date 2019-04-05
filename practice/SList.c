#pragma once 

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<malloc.h>


typedef int DataType;

// 定义结点结构体
typedef struct Node{
  DataType value;     // 保存这个节点的值
  struct Node* next;  // 保存下一个结点的地址
} Node;

// 定义第一个结点的地址
typedef struct SList{
  Node* first;    // 第一个结点的地址
} SList;


// 初始化
void SListInit(SList* SList){
  assert(SList);  // 判断链表是否存在
  SList->first = NULL;    // 不存在则把链表的第一个结点置空
}


// 头插
void SListPushFront(SList* slist, DataType data){
  assert(slist);
  // 1. 空链表
  // 2. 链表非空
  
  // 创建结点
  // 开辟结点空间
  Node* node = (Node*)malloc(sizeof(Node));
  // 给结点值
  node->value = data;

  // 改变结点关系
  node->next = slist->first;
  slist->first = node;
}


// 尾插
void SListPushBack(SList* slist, DataType data){
  assert(slist);

  Node* node = (Node*)malloc(sizeof(Node));
  node->value = data;
  node->next = NULL;

  // 1. 链表为空
  if(slist->first == NULL){
    slist->first = node;
  }

  // 2. 链表不为空
  // 遍历链表，找到最后一个结点
  else{
    Node* cur = slist->first;
    while(cur->next != NULL){
      cur = cur->next;
    }
    cur->next = node;
  }
}


// 头删
void SListPopFront(SList* slist){
  // 头删 必须保证链表中有元素
  assert(slist->first != NULL);

  // 删除后头结点要能找到剩下的链表
  Node* second = slist->first->next;
  free(slist->first);
  slist->first = second;
}


// 尾删
void SListPopBack(SList* slist){
  // 1. 保证链表中有元素
  assert(slist->first != NULL);

  // 2. 找到链表倒数第二个结点
  Node* cur = slist->first;
  while(cur->next->next != NULL){
    cur = cur->next;
  }
  free(cur->next);
  cur->next = NULL; 
}

// 查找值为 data 的结点
Node* SListFind(SList* slist, DataType data){
  assert(slist);

  Node* cur = slist->first;
  while(cur->value != data){
    cur = cur->next;
  }
  if(cur != NULL){
    return cur;
  }
  else{
    return NULL;
  }
}

// 在 pos 结点之后插入
void SListInsertAfter(SList* slist, Node* pos, DataType data ){
  assert(slist->first);

  (void)slist;
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = data;

  node->next = pos->next;
  pos->next = node;

}


// 在 pos 结点之后删除
void SListEraseAfter(SList* slist, Node* pos){
  // 1.链表不为空
  assert(slist->first);
  (void)slist;
  
  Node* cur = pos->next->next;
  free(pos->next);
  pos->next = cur;
}

// 删除链表中第一个值为 data 的结点
void SListRemove(SList* slist, DataType data){
  assert(slist);

  // 链表中没有结点
  if(slist->first == NULL){
    return ;
  }

  // 链表中有结点
  // 判断链表中第一个结点的值是不是要删除 结点的值
  // 如果是，头删，不是则遍历链表，查找结点值为 data 的结点
  if(slist->first->value == data){
    Node* second = slist->first->next;
    free(slist->first);
    slist->first = second;
  }

  Node* prev = slist->first;
  Node* cur = prev->next;
  while(cur->value != data){
    cur = cur->next; 
    prev = prev->next;
  }
  if(cur != NULL){
    Node* next = cur->next;
    free(cur);
    prev->next = next;
  }
  else{
    return;
  }
}


// 删除链表中所有值等于 data 的结点
void SListRemoveAll(SList* slist, DataType data){
  assert(slist);

  if(slist->first == NULL){
    return ;
  }

  Node* cur = slist->first;
  while(cur->next != NULL){
    if(cur->next->value == data){
      Node* next = cur->next;
      cur->next = cur->next->next;
      free(next);
    }
    else{
      cur = cur->next;
    }
  }

  if(slist->first->value == data){
    Node* first = slist->first;
    slist->first = slist->first->next;
    free(first);
  }
}

// 链表销毁
void SListDestroy(SList* slist){
  assert(slist);

  while(slist->first != NULL){
    SListPopBack(slist);
  }
}


void PrintSList(SList* slist){
  assert(slist);

  Node* cur = slist->first;
  while(cur != NULL){
    printf("%d ", cur->value);
    cur = cur->next;
  }
  printf("\n");
}

void test(){
  SList slist;
  SListInit(&slist);

  SListPushFront(&slist, 3);
  SListPushFront(&slist, 2);
  SListPushFront(&slist, 1);
  PrintSList(&slist);

  SListPushBack(&slist, 4);
  SListPushBack(&slist, 5);
  SListPushBack(&slist, 6);
  PrintSList(&slist);

  SListPopFront(&slist);
  SListPopFront(&slist);
  SListPopFront(&slist);
  PrintSList(&slist);

  SListPopBack(&slist);
  SListPopBack(&slist);
  PrintSList(&slist);

  Node* pos = SListFind(&slist, 4);

  SListInsertAfter(&slist, pos, 8);
  SListInsertAfter(&slist, pos, 7);
  SListInsertAfter(&slist, pos, 6);
  SListInsertAfter(&slist, pos, 5);
  PrintSList(&slist);

  Node* Pos = SListFind(&slist, 6);
  SListEraseAfter(&slist, Pos);
  SListEraseAfter(&slist, Pos);
  PrintSList(&slist);

  SListInsertAfter(&slist, pos, 8);
  SListInsertAfter(&slist, pos, 7);
  SListInsertAfter(&slist, pos, 6);
  PrintSList(&slist);

  SListRemove(&slist, 6);
  PrintSList(&slist);


  SListInsertAfter(&slist, pos, 6);
  SListInsertAfter(&slist, pos, 6);
  SListInsertAfter(&slist, pos, 6);
  SListPushBack(&slist, 5);
  SListPushBack(&slist, 6);
  SListPushFront(&slist, 6);
  PrintSList(&slist);

  SListRemoveAll(&slist, 6);
  PrintSList(&slist);

  SListDestroy(&slist);
}


int main(){
  test();

  return 0;
}
