#pragma once 
#include<stdio.h>
#include<stdlib.h>


typedef int DataType;

typedef struct BSTreeNode{
  DataType key;
  struct BSTreeNode* left;
  struct BSTreeNode* right;
} BSTreeNode;

// 查找
// 递归形式 0 表示查找失败 1 表示查找成功
int BSTreeFind(const BSTreeNode* root, DataType key);

// 非递归形式查找
int BSTreeFind2(const BSTreeNode* root, DataType key);

// 插入
int BSTreeInsert(BSTreeNode** root, DataType key);

// 递归插入
int BSTreeInsert2(BSTreeNode** root, DataType key);

// 删除
int BSTreeNodeRemove(BSTreeNode** root, DataType key);

void BSTreeTest();
