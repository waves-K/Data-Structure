#include<malloc.h>
#include<assert.h>



typedef int DataType;

typedef struct DListNode{
  DataType data;
  struct DListNode* prev;
  struct DListNode* next;
} DListNode;


// 初始化
// 1. 需要找到头结点就需要一个指针来指向头结点的地址，因此这个指针一定不能为空。
//    从而找到这个头结点
// 2. 需要一个头结点，此时需要给这个头结点开辟一块空间,用来存放头结点中的数据
//    1)头结点的前驱->头结点
//    2)头结点的后继->头结点
//    3)指向头结点的指针 指向 头结点
// 3. 由于初始化针对链表进行操作的，所以参数参数就是一个二级指针
void DListInit(DListNode** ppHead){
  assert(ppHead != NULL);

  DListNode* pHead = (DListNode*)malloc(sizeof(DListNode));
  pHead->next = pHead;
  pHead->prev = pHead;
  *ppHead = pHead;
  
}


//// 查找结点值为 data 的结点 pos 
//DListNode* DListFind(DListNode* pHead, DataType data){
//  //assert(ppHead);
//  
//  DListNode* cur = pHead;
//  if(pHead->next == NULL){
//    return NULL;
//  }
//  else{
//    cur = cur->next;
//  }
//  while(cur != pHead){
//    if(cur->data == data){
//      return cur;
//    }else{
//      cur = cur->next;
//    }
//  }
//  return NULL;
//}
//
//// 任意位置插入
//void DListInsert(DListNode* pHead, DListNode* pos, DataType data){
//  //assert(ppHead);
//  (void)pHead;
//  
//  DListNode* node = (DListNode*)malloc(sizeof(DListNode));
//  node->data = data;
//
//  // pos 结点之后插入 新结点
//  //node->next = pos->next;
//  //node->prev = pos;
//  //pos->next->prev = node;
//  //pos->next = node;
//
//  // pos 结点之前插入新结点
//  node->prev = pos->prev;
//  node->next = pos;
//  pos->prev->next = node;
//  pos->prev = node;
//}


// 头插
void DListPushFront(DListNode* pHead, DataType data){
  //assert(ppHead);

  DListNode* node = (DListNode*)malloc(sizeof(DListNode));
  node->data = data;

  node->next = pHead->next;
  node->prev = pHead;
  pHead->next = node;

  // 调用任意位置插入函数实现头插
  // DListInsert(pHead, pHead->next, data);
}


//// 尾插
//// 相当于是在头结点之前插入一个新结点
//void DListPushBack(DListNode* pHead, DataType data){
//  //assert(ppHead);
//
//  DListNode* node = (DListNode*)malloc(sizeof(DListNode));
//  node->data = data;
//
//  node->prev = pHead->prev;
//  node->next = pHead;
//  pHead->prev->next = node;
//
//  // 调用任意位置插入函数来实现在尾插
//  // DListInsert(pHead, pHead->prev, data);
//}


// 销毁
void DListDestroy(DListNode** ppHead){
  assert(ppHead);

  DListNode* pHead = *ppHead;
  DListNode* cur = pHead->next;
  DListNode* next;
  while(cur != pHead){
    next = cur->next;
    free(cur);
    cur = cur->next;
  }
  *ppHead = NULL;
}




void PrintDList(DListNode* pHead){
  //assert(ppHead);

  if(pHead->next == NULL){
    return ;
  }
  DListNode* cur = pHead->next;
  while(cur != pHead){
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf("\n");
}

void Test()
{
  DListNode* ppHead;
  DListNode pHead;

  DListInit(&ppHead);

  DListPushFront(&pHead, 4);
  DListPushFront(&pHead, 3);
  DListPushFront(&pHead, 2);
  DListPushFront(&pHead, 1);
  DListPushFront(&pHead, 0);
  PrintDList(&pHead);



  DListDestroy(&ppHead);

}



int main()
{
  Test();

  return 0;
}
