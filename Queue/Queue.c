#include"Queue.h"

void QueueInit(Queue* pQ){
    assert(pQ);
    pQ->pFront = NULL;
    pQ->pRear = NULL;
    pQ->size = 0;
}

void QueuePush(Queue* pQ, QDataType data){
    assert(pQ);

    QNode* pNode = (QNode*)malloc(sizeof(QNode));
    assert(pNode);
    pNode->data = data;
    pNode->pNext = NULL;
    pQ->size++;

    if(pQ->pRear == NULL){
        pQ->pFront = pQ->pRear = pNode;
        return;
    }
}


void QueuePop(Queue* pQ){
    assert(pQ);

    assert(pQ->size > 0);
    QNode* pFront;
    pQ->size--;

    pFront = pQ->pFront;
    pQ->pFront = pQ->pFront->pNext;
    free(pFront);

    if(pQ->pFront == NULL){
        pQ->pRear = NULL;
    }
}


QDataType QueueFront(Queue* pQ){
    assert(pQ);

    assert(pQ->size > 0);

    return pQ->pFront->data;
}


int QueueSize(Queue* pQ){
    assert(pQ);
    return pQ->size;
}


int QueueIsEmpty(Queue* pQ){
    assert(pQ);
    return pQ->size == 0 ? 1 : 0;
}


void QueueDestroy(Queue* pQ){
    QNode* pNode;
    QNode* pNext;
    for(pNode = pQ->pFront; pNode != NULL; pNode = pNext){
        pNext = pNode->pNext;
        free(pNode);
    }
    pQ->pFront = pQ->pRear = NULL;
    pQ->size = 0;
}
