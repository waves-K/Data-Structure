#include"BSTree.h"

// 递归形式查找
// 0 表示查找失败 1 表示查找成功
int BSTreeFind(const BSTreeNode* root, DataType key){
  if(root == NULL){
    return 0;
  }

  if(key == root->key){
    return 1;
  }

  else if(key > root->key){
    return BSTreeFind(root->right,key);
  }

  else{
    return BSTreeFind(root->left, key);
  }
}


// 非递归查找
int BSTreeFind2(const BSTreeNode* root, DataType key){
  BSTreeNode* cur = (BSTreeNode*)root;
  while(cur != NULL){
    if(key == cur->key){
      return 1;
    }
    else if(key > cur->key){
      cur = cur->right;
    }
    else{
      cur = cur->left;
    }
  }
  return 0;
}


// 插入
int BSTreeInsert(BSTreeNode** root, DataType key){
  BSTreeNode* cur = *root;
  BSTreeNode* parent = NULL;
  while(cur != NULL){
    if(key == cur->key){
      // 重复了，插入失败
      return 0;
    }
    parent = cur;
    if(key > cur->key){
      cur = cur->right;
    }
    else{
      cur = cur->left;
    }
  }
  BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
  node->key = key;
  node->left = node->right = NULL;

  if(parent == NULL){
    // 空树中插入
    *root = node;
    return 1;
  }

  if(key < parent->key){
    parent->left = node;
  }
  else{
    parent->right = node;
  }
  return 1;
}



void Test(){
  BSTreeNode* root = NULL;
  int r;
  r = BSTreeInsert(&root, 5);printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 3);printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 7);printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 1);printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 4);printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 6);printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 8);printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 0);printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 2);printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 9);printf("插入%s\n", r ? "成功" : "失败");
  

  r = BSTreeFind(root, 9);printf("查找 9 %s\n", r ? "成功" : "失败");
  r = BSTreeFind2(root, 19);printf("查找 19 %s\n", r ? "成功" : "失败");
}
