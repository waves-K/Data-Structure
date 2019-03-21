// 这是一个测试函数

#include"SeqList.h"

int main(){
    SeqList s;
    SeqListInit(&s);

    SeqListPushBack(&s, 1);
    SeqListPushBack(&s, 2);
    SeqListPushBack(&s, 3);
    SeqListPushBack(&s, 4);
    SeqListPushBack(&s, 5);
    PrintSeqList(&s);

    SeqListPopBack(&s);
    SeqListPopBack(&s);
    PrintSeqList(&s);

    SeqListPushFront(&s, 0);
    SeqListPushFront(&s, 8);
    SeqListPushFront(&s, 9);
    PrintSeqList(&s);

    SeqListPopFront(&s);
    PrintSeqList(&s);

    SeqListInsert(&s, 1, 7);
    SeqListInsert(&s, 5, 6);
    PrintSeqList(&s);

    SeqListErase(&s, 1);
    SeqListErase(&s, 5);
    PrintSeqList(&s);

    SeqListFind(&s, 3);

    SeqListRemove(&s, 3);
    PrintSeqList(&s);


    SeqListDestory(&s);

    return 0;
}
