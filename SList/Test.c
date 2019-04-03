#include"SList.h"

int main(){
    SList sl;
    SListInit(&sl);
    SListPushFront(&sl, 1);
    SListPushFront(&sl, 2);
    SListPushFront(&sl, 3);
    SListPushFront(&sl, 4);
    SListPushFront(&sl, 5);
    SListPrint(&sl);

    //SListPushBack(&sl, 1);
    //SListPushBack(&sl, 2);
    //SListPushBack(&sl, 3);
    //SListPushBack(&sl, 4);
    //SListPrint(&sl);

    //SListPopFront(&sl);
    //SListPopFront(&sl);
    //SListPopFront(&sl);
    //SListPrint(&sl);

    //SListPopBack(&sl);
    //SListPopBack(&sl);
    //SListPrint(&sl);

    //Node *SListFind(&sl, 2);
    //
    //SListPushFront(&sl, 3);
    //SListPushFront(&sl, 4);
    //SListPushFront(&sl, 5);
    //SListPushFront(&sl, 6);
    //SListPrint(&s);

    //SListInsertAfter(&sl, 3, 7);
    //SListPrint(&sl);

    //SListEraseAfter(&sl, 3);
    //SListPrint(&sl);

    //SListPushBack(&sl, 5);
    //SListPrint(&sl);

    //SListRemove(&sl, 5);
    //SListPrint(&sl);

    //SListRemoveAll(&sl, 1);
    //SListPrint(&sl);
    //system("pause");
    //return 0;
}
