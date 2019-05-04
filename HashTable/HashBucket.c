// 哈希桶

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#

typedef int Key;

typedef struct Node {
    Key key;
    struct Node *next;
} Node;

typedef struct {
    int size;
    int capacity;
    Node ** array;
} HashBucket;


void HashBucketInit(HashBucket *pHB, int capacity){
    pHB->array = (Node **)malloc(sizeof(Node *) * capacity);
    pHB->size = 0;
    pHB->capacity = capacity;

    for (int i = 0; i < capacity; ++i) {  
        pHB->array[i] = NULL;
    }
}

void ListDestroy(Node *first){
    Node *next;
    for (Node *cur = first; cur != NULL; cur = next) {
        next = cur->next;
        free(cur);
    }
}

void HashBucketDestroy(HashBucket *pHB){
    // 需要先释放 哈希桶 链表
    for (int i = 0; i < pHB->capacity; ++i) {
        ListDestroy(pHB->array[i]);
    }

    // 在释放哈希桶
    free(pHB->array);
}

// 查找
// 找到返回所在节点地址
// 没找到返回 NULL
Node *HashBucketSearch(HashBucket *pHB, Key key){
    int index = key % pHB->capacity;
    Node *cur = pHB->array[index];
    while (cur != NULL) {
        if (cur->key == key) {
            return cur;
        }

        cur = cur->next;
    }

    return NULL;
}

int HashBucketInsert(HashBucket *pHB, Key key); 

void ExpandIfRequired(HashBucket *pHB){
    if (pHB->size < pHB->capacity) {
        return;
    }

    HashBucket newHB;
    HashBucketInit(&newHB, pHB->capacity * 2);

    for (int i = 0; i < pHB->capacity; ++i) {
        for (Node *cur = pHB->array[i]; cur != NULL; cur = cur->next) {
            HashBucketInsert(&newHB, cur->key);
        }
    }

    HashBucketDestroy(pHB);

    pHB->array = newHB.array;
    pHB->capacity = newHB.capacity;
}

// 插入 (和开放地址法不同，没有负载因子的概念)
// 成功返回 0    失败返回 -1
int HashBucketInsert(HashBucket *pHB, Key key) {
    ExpandIfRequired(pHB);

    if (HashBucketSearch(pHB, key) != NULL) {
        return -1;
    }


    int index = key % pHB->capacity;
    Node *first = pHB->array[index];
    Node * newNode = (Node *)malloc(sizeof(Node));

    // 头插
    newNode->next = first;
    pHB->array[index] = newNode;
    pHB->size++;

    // // 插入到第二个位置
    // if (first == NULL) {

    // } else {
    //     newNode->next = first->next;
    //     first->next = newNode;
    // }
    return 0;
} 


// 删除
int HashBucketRemove(HashBucket *pHB, Key key) {
    int index = key % pHB->capacity;
    Node *prev = NULL;
    for (Node *cur = pHB->array[index]; cur != NULL; cur = cur->next) {
        if (cur->key == key) {
            // 删除
            if (prev == NULL) {
                // 如果要删除的节点是第一个节点
                pHB->array[index] = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            pHB->size--;
            return 0;
        }

        prev = cur;
    }
    return -1;
}


void Test() {
    HashBucket hb;
    HashBucketInit(&hb, 10);

    for (int i = 0; i < 100; ++i) {
        HashBucketInsert(&hb, 0 + i * 10);
    }

    
    printf("%p\n", HashBucketSearch(&hb, 20));
    HashBucketRemove(&hb, 20);
    printf("%p\n", HashBucketSearch(&hb, 20));
}


int main() {
    Test();
    return 0;
}
