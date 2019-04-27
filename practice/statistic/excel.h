/* 统计水果
 * 找全班最喜欢的 k 种水果
 *    1.统计每种水果被喜欢的次数
 *    2.找到其中的 top k
 */

#pragma once 

#include <stdlib.h>
#include <stdio.h>


static char *fruits[] = {
    "apple", "pear", "banana", "orange"
};

int size = sizeof(fruits) / sizeof(char *);

void Generate(){
    srand(20190426);
    for (int i = 0; i < 60; i++){
        printf("    \"%s\", ", fruits[rand() % size]);
    }
}

static char *favor_fruits[] = {
    "banana", 
    "apple" ,
    "banana" ,
    "orange" ,
    "banana" ,
    "orange" ,
    "banana" ,
    "banana" ,
    "orange" ,
    "orange" ,
    "orange" ,
    "pear" ,
    "pear" ,
    "apple" ,
    "pear" ,
    "pear" ,
    "pear" ,
    "orange", 
    "banana" ,
    "pear" ,
    "banana", 
    "banana" ,
    "banana" ,
    "apple" ,
    "banana" ,
    "banana" ,
    "apple" ,
    "apple" ,
    "banana" ,
    "banana" ,
    "orange" ,
    "apple" ,
    "orange" ,
    "pear" ,
    "orange", 
    "pear" ,
    "apple" ,
    "pear" ,
    "orange", 
    "orange" ,
    "apple" ,
    "banana" ,
    "apple" ,
    "banana" ,
    "orange" ,
    "banana" ,
    "orange" ,
    "apple" ,
    "pear" ,
    "pear" ,
    "pear" ,
    "orange", 
    "apple" ,
    "orange" ,
    "apple" ,
    "banana" ,
    "pear" ,
    "apple" ,
    "banana" ,
    "orange"
};

int favor_size = sizeof(favor_fruits) / sizeof(char *);

typedef struct ResultItem{
    char fruit[20];   // key
    int count;        // value
} ResultItem;

typedef struct Node{
    struct ResultItem data;
    struct Node *left;
    struct Node *right;
} Node;

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


void Insert(Node **root, char *fruit){
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->data.fruit, fruit);
    node->data.count = 1;
    node->left = node->right = NULL;

    if (*root == NULL) {
        *root = node;
        return ;
    }

    int ret = strcmp((*root)->data.fruit, fruit);
    // 我们外边保证一定不会插入 fruit 重复的值
    assert(ret != 0);

    if (ret < 0) {
        Insert(&(*root)->left, fruit);
    } else {
        Insert(&(*root)->right, fruit);
    }
}

ResultItem *Find(Node *root, char *fruit){
    if (root == NULL) {
        return NULL;
    }

    int ret = strcmp(root->data.fruit, fruit);
    if (ret == 0) {
        // 这里一定是返回地址
        return &root->data;
    }

    if (ret < 0) {
        return Find(root->left, fruit);
    } else {
        return Find(root->right, fruit);
    }
}

void PreOrder(ResultItem *result_size, Node *root){
    if (root == NULL) {
        return ;
    }

    int i;
    switch (root->data.fruit[0]){
        case 'a':
            // apple
            i = 0;
            break;
        case 'b':
            // banana
            i = 1;
            break;
        case 'o':
            // orange
            i = 2;
            break;
        case 'p':
            // pear
            i = 3;
            break;
    }

    result_size[i] = root->data;
    printf("%s %d\n", root->data.fruit, root->data.count);

    // SeqListPushBack(&seqList, root->data);

    PreOrder(result_size, root->left);
    PreOrder(result_size, root->right);
}

ResultItem *StaticsFruitCount(char *fruits[], int size, int *pResultSize){
    // 假设有个集合 Set 
    // 1.顺序表
    // 2.二叉搜索树
    // 3.哈希表
    // 正常考虑，我们这个数据量，用顺序表更加合适
    // 出于学习目的，我们强行用二叉树
    struct Node *root = NULL;
    
    for (int i = 0; i < size; i++) {
        char *fruit = fruits[i];

        ResultItem *item = Find(root, fruit);

        if (item != NULL){
            // 如果已经有过，出现次数 + 1
            item->count++;
        } else {
            // 如果没有出现过，放进去，次数是 1 次
            Insert(&root, fruit);
        }
    }

    // 前序遍历的方式取出来
    ResultItem *result = (ResultItem *)malloc(4 * sizeof(ResultItem));
    PreOrder(result, root);

    // root 是每个水果出现的次数
    *pResultSize = 4;
    return result;
}

void ArrayAdjustDown(ResultItem array[], int size, int root){
    int parent = root;

    while (1) {
        // 先判断有没有孩子(叶子节点)
        // 数组角度去想-》孩子的下标是否越界
        // 只要判断左孩子的下标(因为是完全二叉树)
        int left = parent * 2 + 1;
        if (left >= size) {
            // 越界，没有左孩子，也肯定没有右孩子
            return ;
        }

        // 一定有左孩子
        int maxChild = left;
        if (2 * parent + 2 < size && array[2 * parent +2].count < array[left].count) {
            // 前一个条件是判断有没有右孩子
            // 后一个条件是判断右孩子是不是比左孩子大
            maxChild = 2 * parent + 2;
        }

        if (array[parent].count < array[maxChild].count) {
            return ;
        }

        // 交换 root 和 maxChild 下标所在的值
        ResultItem t = array[parent];
        array[parent] = array[maxChild];
        array[maxChild] = t;

        parent = maxChild;
    }
}

ResultItem *TopK(ResultItem *result, int size, int k){
    ResultItem *heap = (ResultItem *)malloc(sizeof(ResultItem) * k);
    assert(heap);

    for (int i = 0; i < k; i++) {
        heap[i] = result[i];
    }

    for (int j = (k - 2) / 2; j >= 0; j--){
        ArrayAdjustDown(heap, k, j);
    }
    for (int m = k; m < size; m++) {
        if (result[m].count > heap[0].count) {
            heap[0] = result[m];
            ArrayAdjustDown(heap, k, 0);
        }
    }
    return heap;
}

void FindTopK(){
    int result_size;
    // result 有多少个元素， result_size 个
    ResultItem *result = StaticsFruitCount(favor_fruits, favor_size, &result_size);
    // topk 有多少个元素，答案就是 k 个
    ResultItem *topk = TopK(result, result_size, 2);

    for (int i = 0; i < 2; i++) {
        printf("%s %d\n", topk[i].fruit, topk[i].count);
    }
}
