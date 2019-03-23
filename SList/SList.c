#include"SList.h"

// 单链表初始化
void SListInit(SList *slist){
    slist->first = NULL;
}

// 单链表头插
// 注意问题：
//    1.链表为空  first --> NULL
//    2.链表不为空  first -- > 1 -- > 2 --> 3 --> 4 --> NULL
//经过思考，链表为空和不为空的情形是一样的，所以不需要做特殊处理
void SListPushFront(SList *slist, SListDataType data){
    // 1.创建新结点,就是给结点开辟新空间
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = data;

    // 2.更改链表的关系
    node->next = slist->first;
    slist->first = node;
}

// 尾插
void SListPushBack(SList *slist, SListDataType data){
    // 1.创建新结点
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = data;
    node->next = NULL;

   // 2.遍历链表，找到最后一个元素
    if(slist->first == NULL){
        slist->first = node;
    }
    else{
        // 找原来链表的最后一个结点
        Node *current = slist->first;
        while(current->next != NULL){
            current = current->next;
        }

        // 循环结束，此时 current->next 一定是 NULL,也就是链表最后一个节点
        current->next = node;
    }
}


// 头删
void SListPopFront(SList *slist){
    // 1.链表中没有节点
    assert(slist->first != NULL);

    // 2.链表中有结点
    // 由于是头删，如果直接删除链表第一个结点
    // 就会导致链表的头指针找不到链表的第二个结点
    // 为了避免这种情况，先定义一个指针，用来存放链表第二个节点的位置
    Node *second = slist->first->next;
    free(slist->first);
    slist->first = second;
}

// 尾删
void SListPopBack(SList *slist){
    // 排除链表中没有结点的情况
    assert(slist->first != NULL);

    // 只有一个节点的情况
    if(slist->first->next == NULL){
        free(slist->first);
        slist->first = NULL;
        return;
    }

    // 有两个即两个结点以上的情况
    // 找到倒数第二个结点，做记录
    Node *current;
    for(current = slist->first; current->next->next != NULL; current = current->next);
    free(current->next);
    current->next = NULL;
}

// 查找
Node *SListFind(SList *slist, SListDataType data){
    for(Node *current = slist->first; current != NULL; current = current->next){
        if(current->value == data){
            return current;
        }
    }
    return NULL;
}

// 在 pos 结点的后面插入一个结点
void SListInsertAfter(SList *slist, Node *pos, SListDataType data){
    (void)slist;
    // 1.创建新结点
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = data;
    node->next = pos->next;
    pos->next = node;
}

// 在 pos 结点的后面删除一个结点
void SListEraseAfter(SList *slist, Node *pos){
    // 这句代码是为了消除 slist 变量未被使用的警告
    (void)slist;
    // 定义一个指针，保留 pos 结点之后的第二个结点的地址
    Node *next = pos->next->next;
    free(pos->next);
    pos->next = next;
}

// 删除第一个结点值为 data 的结点
void SListRemove(SList *slist, SListDataType data){
    // 1.先确认第一个节点的值是不是 data 
    // 如果是：头删
    // 如果不是：继续
    // 2.拿一个指针遍历链表的结点，判断指针指向结点的下一个结点保存的值是不是 data
    // 指针符号：current 
    // 指针范围[first, 倒数第二个结点]
    // 3.如果找到了，进行删除
    // current = current->next->next;
    // 释放原来的结点 current->next;
    

    // 第一种情况:链表中一个结点也没有
    if(slist->first == NULL){
        return;
    }

    // 第二种情况：链表中有结点
    // 判断链表中的第一个结点的值是不是 data
    // 链表中的一个结点的值是 data
    if(slist->first->value == data){
        // 记录链表的第二个节点
        Node *second = slist->first->next;
        // 释放第一个结点
        free(slist->first);
        slist->first = second;
    }
    // 链表中的第一个结点的值不是 data
    else{
        // 遍历链表，查找链表中结点的值为 data 的结点
        Node* current = slist->first;
        while(current != NULL){
            if(current->next->value == data){
                Node* next = current->next;
                current->next = current->next->next;
                free(next);
                return;
            }
            current = current->next;
        }
    }
}


// 删除所有值为 data 的结点
void SListRemoveAll(SList *slist, SListDataType data){
    if(slist->first == NULL){
        return;
    }
    Node* current = slist->first;
    while(current->next != NULL){
        if(current->next->value == data){
            Node* next = current->next;
            current->next = current->next->next;
            free(next);
        }
        else{
            current = current->next;
        }
    }
    // 除了第一个结点没有检查，其他的结点都已经检查并删除了
    if(slist->first->value == data){
        // 头删
        Node* first = slist->first;
        slist->first = slist->first->next;
        free(first);
    }
}

// 销毁
void SListDestory(SList *slist){
    while(slist->first != NULL){
    SListPopBack(slist);
    }
}



/////////////////////////////////
// 这是一个测试专用的打印函数
/////////////////////////////////

void SListPrint(SList *slist){
    assert(slist);

    Node* current = slist->first;
    while(current != NULL){
        printf("%d ",current);
        current = current->next;
    }
    printf("\n");
}
