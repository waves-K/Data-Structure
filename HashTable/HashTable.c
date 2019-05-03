#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>


typedef int Key;

typedef enum {
    EMPTY,    // 空的
    EXIST,    // 有数据的
    DELETED   // 被删除的
} State;

typedef struct Element{
    Key key;
    State state;
} Element;

typedef int (*HashFuncType)(Key key, int capacity);

typedef struct HashTable{
    Element *table;
    int size;     // 数据个数
    int capacity; // 容量
    HashFuncType hashFunc;     // 哈希函数
} HashTable;


// 初始化/销毁
void HashInit(HashTable *pHT, int capacity, HashFuncType hashFunc){
    pHT->table = (Element *)malloc(sizeof(Element) * capacity);
    assert(pHT->table);

    pHT->size = 0;
    pHT->capacity = capacity;
    pHT->hashFunc = hashFunc;

    for (int i = 0; i < capacity; ++i) {
        pHT->table[i].state = EMPTY;
    }
}


void HashDestroy(HashTable *pHT){
    free(pHT->table);
}

// 线性探测法
// 查找 [Find/Search/Query]
int HashSearch(HashTable *pHT, Key key){
    int index = pHT->hashFunc(key, pHT->capacity);
    while (pHT->table[index].state != EMPTY) {
        if (pHT->table[index].key == key
                && pHT->table[index].state == EXIST) {
           return index; 
        }

        // 如果 哈希表 存满了，是个死循环
        // 但 哈希表 不会被存满

        // index = index + 1;
        // if (index == pHT->capacity) {
        //     index = 0;
        // }

        index = (index + 1) % pHT->capacity;
    }
    // 没找到
    return -1;
}

int HashInsert(HashTable *pHT, Key key);

void ExpandIfRequired(HashTable *pHT){
    // 不扩容
    if (pHT->size * 10 / pHT->capacity < 7) {
        return ;
    }

#if 0
    // 数据搬移太麻烦了，不要了
    int newCapacity = pHT->capacity * 2;
    Element *newTable = (Element *)malloc(sizeof(Element) * newCapacity);
    assert(newTable);

    // newTable 的状态都更新成 EMPTY 
    for (int i = 0; i < newCapacity; ++i) {
        newTable[i].state = EMPTY;
    }

    // 把老数据搬移过来
    
    free(pHT->table);
    pHT->table = newTable;
    pHT->capacity = newCapacity;
#endif
    HashTable newHT;
    HashInit(&newHT, pHT->capacity * 2, pHT->hashFunc);
    for (int i = 0; i < pHT->capacity; ++i) {
        if (pHT->table[i].state == EXIST) {
            HashInsert(&newHT, pHT->table[i].key);
        }
    }
    free(pHT->table);
    pHT->table = newHT.table;
    pHT->capacity = newHT.capacity;
}

// 插入
// Key 不予许重复
// 0 插入成功   -1 插入失败
int HashInsert(HashTable *pHT, Key key){
    ExpandIfRequired(pHT);

    int index = pHT->hashFunc(key, pHT->capacity);
    while (1) {
        if (pHT->table[index].key == key 
                && pHT->table[index].state == EXIST) {
            return -1;
        }
        if (pHT->table[index].state != EXIST) {
            pHT->table[index].key = key;
            pHT->table[index].state = EXIST;
            pHT->size++;
            return 0;
        }
        
        index = (index + 1) % pHT->capacity;
    }
}

// 删除
// 成功返回 0， 失败返回 -1
int HashRemove(HashTable *pHT, Key key){
    int index = pHT->hashFunc(key, pHT->capacity);
    while (pHT->table[index].state != EMPTY) {
        if (pHT->table[index].key == key
                && pHT->table[index].state == EXIST) {
            pHT->table[index].state = DELETED;
            return 0;
        }
        index = (index + 1) % pHT->capacity;
    }
    return -1;
}

// 哈希函数
int mod(Key key, int capacity){
    return key % capacity;
}

void Test(){
    HashTable ht;
    HashInit(&ht, 10, mod);

    HashInsert(&ht, 1);
    HashInsert(&ht, 11);
    HashInsert(&ht, 21);
    HashInsert(&ht, 31);
    HashInsert(&ht, 41);
    HashInsert(&ht, 51);
    HashInsert(&ht, 61);
    HashInsert(&ht, 71);
    HashInsert(&ht, 81);

    printf("%d\n", HashSearch(&ht, 1));
    HashRemove(&ht, 1);
    printf("%d\n", HashSearch(&ht, 1));

    HashDestroy(&ht);
}

int main(){
    Test();
    return 0;
}
