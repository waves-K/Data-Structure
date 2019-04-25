#include <stdio.h>
#include <malloc.h>



typedef int DataType;

typedef struct BSTreeNode{
    DataType key;
    struct BSTreeNode *left;
    struct BSTreeNode *right;
}   BSTreeNode;

// 递归形式
// 0 表示朝朝失败，1 表示成功
int BSTreeFind(const BSTreeNode *root, DataType key){
    if(root == NULL){
        return 0;
    }
    if(key == root->key){
        return 1;
    }
    if (key > root->key){
        return BSTreeFind(root->right, key);
    }
    if (key < root->key){
        return BSTreeFind(root->left, key);
    }

    return 0;
}

// 非递归
int BSTreeFind2(const BSTreeNode *root, DataType key){
    BSTreeNode *cur = (BSTreeNode *)root;
    while(cur != NULL){
        if(key == cur->key){
            return 1;
        }else if (key > cur->key) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return 0;
}


// 插入
int BSTreeInsert(BSTreeNode **root, DataType key){
    // 1.查找
    BSTreeNode *cur = *root;
    BSTreeNode *parent = NULL;
    while (cur != NULL) {
        if (key == cur->key) {
            // 重复了,插入失败
            return 0;
        }
        
        parent = cur;
        if (key > cur->key) {
            cur = cur->right;
        } else {
            cur =cur->left;
        }
    }
    BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
    node->key = key;
    node->left = node->right = NULL;

    if (parent == NULL) {
        // 空树中插入
        *root = node;
        return 1;
    }

    if (key < parent->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    return 1;
}

// 插入递归
int BSTreeInsert2(BSTreeNode **root, DataType key){
    if (*root == NULL) {
        BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
        node->key = key;
        node->left = node->right = NULL;

        *root = node;
        return 1;
    } 
    if (key == (*root)->key) {
        return 0;
    }
    if (key < (*root)->key) {
        // 这个是不对的，更改的只是栈上临时变量的值
        // BSTreeNode *child = (*root)->left;
        // return BSTreeFind2(&child, key);
        return BSTreeInsert2(&(*root)->left, key);
    } else {
        return BSTreeInsert2(&(*root)->right, key);
    }
    return 1;
}

void Test(){
    int r;
    BSTreeNode *root = NULL;
    r = BSTreeInsert(&root, 5); printf("插入%s\n", r ? "成功" : "失败");
    r = BSTreeInsert(&root, 3); printf("插入%s\n", r ? "成功" : "失败");
    r = BSTreeInsert(&root, 7); printf("插入%s\n", r ? "成功" : "失败");
    r = BSTreeInsert(&root, 1); printf("插入%s\n", r ? "成功" : "失败");
    r = BSTreeInsert(&root, 4); printf("插入%s\n", r ? "成功" : "失败");
    r = BSTreeInsert(&root, 6); printf("插入%s\n", r ? "成功" : "失败");
    r = BSTreeInsert(&root, 8); printf("插入%s\n", r ? "成功" : "失败");
    r = BSTreeInsert(&root, 0); printf("插入%s\n", r ? "成功" : "失败");
    r = BSTreeInsert2(&root, 2); printf("插入%s\n", r ? "成功" : "失败");
    r = BSTreeInsert2(&root, 9); printf("插入%s\n", r ? "成功" : "失败");

    r = BSTreeFind(root, 9); printf("查找 9 %s\n", r ? "成功" : "失败");
    r = BSTreeFind2(root, 10); printf("查找 10 %s\n", r ? "成功" : "失败");
}

int main() {
    Test();
    return 0;
}
