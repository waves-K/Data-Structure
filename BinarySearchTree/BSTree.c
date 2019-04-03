#include"BSTree.h"

// 递归形式
// 0 表示产找失败，1 表示查找成功
int BSTreeFind(const BSTreeNode* root, DataType key){
  // 空树，查找失败，返回 0
  if(root == NULL){
    return 0;
  }

  // 根结点的值等于要查找的值，查找成功，返回 1
  if(key == root->key){
    return 1;
  }
  // 要查找的值大于根结点的值
  // 在右子树中递归查找
  else if(key > root->key){
    return BSTreeFind(root->right, key);
  }
  
  // 要查找的值小于根结点的值
  // 在左子树中递归查找
  else{
    return BSTreeFind(root->left, key);
  }
}


// 非递归
int BSTreeFind2(const BSTreeNode* root, DataType key){
  // 定义一个指向更结点的指,用来记录当前结点
  BSTreeNode* cur = (BSTreeNode*)root;
  // 当 cur 不为空的时候 循环继续 
  while(cur != NULL){
    // 当要找到值 key 等于 cur->key 时 查找成功，返回 1
    if(key == cur->key){
      return 1;
    }

    // 当要查找的值 key 大于 cur->key 时，在树的右子树中查找
    else if(key > cur->key){
      cur = cur->right;
    }

    // 否则在树的左子树中查找
    else{
      cur = cur->left;
    }
  }
  return 0;
}


// 插入
int BSTreeInsert(BSTreeNode** root, DataType key){
  BSTreeNode* cur = *root;
  
  // 记录 parent 的位置
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
  node->left = node->right = node;

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


// 递归插入
int BSTreeInsert2(BSTreeNode** root, DataType key){
  if(*root == NULL){
    BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
    node->key = key;
    node->left = node->right = NULL;
    *root = node;
    return 1;
  }

  if(key == (*root)->key){
    return 0;
  }

  if(key < (*root)->key){
    // 这个是不对的，更改的只是栈上临时变量的值
    // BSTreeNode* child = (*root)->left;
    // retutn BSTreeInsert2(&child, key);
    return BSTreeInsert2(&(*root)->left, key);
  }
  else{
    return BSTreeInsert2(&(*root)->right, key);
  }
}

// 删除右为空的情况
static void RemoveRightNULL(BSTreeNode* parent, BSTreeNode** root, BSTreeNode* cur, DataType key){
  if(parent == NULL){
    // 要删除的就是更结点
    *root = cur->left;
  }
  else{
    if(key < parent->key){
      // cur 是 parent 的 left 
      parent->left = cur->left;
    }
    else{
      // cur 是 parent 的 right 
      parent->right = cur->left;
    }
  }
  free(cur);
}

// 删除左为空的情况
static void RemoveLeftNULL(BSTreeNode* parent, BSTreeNode** root, BSTreeNode* cur,DataType key){
  if(parent == NULL){
    // 要删除的就是更结点
    *root = cur->right;
  }
  else{
    if(key < parent->key){
      // cur 是 parent 的 left 
      parent->left = cur->right;
    }
    else{
      // cur 是 parent 的 right 
      parent->right = cur->right;
    }
  }
  free(cur);
}

static void RemoveHasLeftAndRight(BSTreeNode* cur){

        // 找左子树中最大的
        BSTreeNode* del = cur->left;
        BSTreeNode* delpParent = NULL;
        while(del->right != NULL){
          delpParent = del;
          del = del->right;
        }
        // del 就是左子树中最大的
        
        cur->key = del->key;
        // 删除 del 结点
        if(delpParent == NULL){
          // 左孩子中最大的就是 cur 的左孩子
          cur->left = del->left;
        }
        else{
          delpParent->right = del->left;
        }
        free(del);
}

// 删除
// 找到就删除，返回成功 1
// 没找到删除失败，返回失败 0
int BSTreeNodeRemove(BSTreeNode** root, DataType key){
  // 先查找，后删除
  BSTreeNode* cur = *root;
  BSTreeNode* parent = NULL;
  while(cur != NULL){
    if(key == cur->key){
      // 这里找到了，这里是删除的地方
      if(cur->left == NULL){
        // cur 没有左孩子

        RemoveLeftNULL(parent, root, cur, key);
//        if(parent == NULL){
//          // 要删除的就是根结点
//          *root = cur->right;
//        }
//        else{
//
//          if(key < parent->key){
//            // cur 是 parent 的 left
//            parent->left = cur->right;
//          }
//          else{
//            // cur 是 parent 的 right
//            parent->right = cur->right;
//          }
//        }
      }
      else if(cur->right == NULL){
        // cur 没有右孩子
        RemoveRightNULL(parent, root, cur, key);
      }
      else{
        // 左右孩子都不为空
        RemoveHasLeftAndRight(cur);

//        找左子树中最大的
//        BSTreeNode* del = cur->left;
//        BSTreeNode* delpParent = NULL;
//        while(del->right != NULL){
//          delpParent = del;
//          del = del->right;
//        }
//        // del 就是左子树中最大的
//        
//        cur->key = del->key;
//        // 删除 del 结点
//        if(delpParent == NULL){
//          cur->left = del->left;
//        }
//        else{
//          delpParent->right = del->left;
//        }
//        free(del);
      }
      return 0;
    }

    parent = cur;
    if(key < cur->key){
      cur = cur->left;
  }
    else{
      cur = cur->right;
    }
  }
  return 0;
}

// 递归删除
int BSTreeNodeRemove2(BSTreeNode** root, DataType key){
  if(*root == NULL){
    return 0;
  }

  if(key == (*root)->key){
    BSTreeNode* del = *root;
    if((*root)->left == NULL){
      // 1. 要删除的不是根
      // 2. 判断要删除的结点是根的左还是右
      *root = (*root)->right;
      free(del);
    }
    else if((*root)->right == NULL){
      *root = (*root)->left;
      free(del);
    }
    else{
      // 左右孩子都不为空
      RemoveHasLeftAndRight(*root);
    }
    return 1;
  }
  if(key < (*root)->key){
    return BSTreeNodeRemove2(&(*root)->left, key);
  }
  else{
    return BSTreeNodeRemove2(&(*root)->right, key);
  }
}

void InOrder(BSTreeNode* root){
  if(root ==NULL){
    return;
  }
  InOrder(root->left);
  printf("%d ", root->key);
  InOrder(root->right);
}

void BSTreeTest(){
  BSTreeNode* root = NULL;
  int r;
  r = BSTreeInsert(&root, 5); printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 3); printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 7); printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 1); printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 4); printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 6); printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 8); printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 0); printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 2); printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert(&root, 9); printf("插入%s\n", r ? "成功" : "失败");
  r = BSTreeInsert2(&root, 19); printf("插入%s\n", r ? "成功" : "失败");

  InOrder(root); printf("\n");

  r = BSTreeFind(root, 9); printf("查找 9 %s\n", r ? "成功" :"失败");
  r = BSTreeFind2(root, 19); printf("查找 19 %s\n", r ? "成功" :"失败");

  BSTreeNodeRemove(&root,8);
  BSTreeNodeRemove(&root,2);
  BSTreeNodeRemove(&root,5);
}
