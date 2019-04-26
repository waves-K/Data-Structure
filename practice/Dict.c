/* 二叉搜索树应用
 * 模拟实现一个简单的字典
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct Dict{
    char    cn[20];   // key
    char    en[20];   // value
    struct Dict *left;
    struct Dict *right;
} Dict;

char *DictFind(const Dict *root, char en[]){
    const Dict *cur = root;
    int ret;
    while (cur != NULL) {
        ret = strncmp(en, cur->en, 20);
        if (ret == 0) {
            return cur->cn;
        } else if (ret > 0) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return NULL;
}

int DictInsert(Dict **root, char en[], char cn[]){
    int ret;
    if (*root == NULL) {
        Dict *node = (Dict *)malloc(sizeof(Dict));
        strncpy(node->en, en, 20);
        strncpy(node->cn, cn, 20);
        node->left = node->right = NULL;
        *root = node;
        return 1;
    }
    ret = strncmp(en, (*root)->en, 20);
    if (ret == 0) {
        return 0;
    }
    if (ret < 0) {
        return DictInsert(&(*root)->left, en, cn);
    } else {
        return DictInsert(&(*root)->right, en, cn);
    }
}

void TestDict(){
    Dict *dict = NULL;
    DictInsert(&dict, "apple", "苹果");
    DictInsert(&dict, "pear", "梨");
    DictInsert(&dict, "orange", "橘子");

    char en[20];
    const char *cn;
    
    while (1) {
        scanf("%s", en);
        if ((cn = DictFind(dict, en)) != NULL) {
            printf("%s\n", cn);
        } else {
            printf("拼写错误\n");
        }
    }
}

int main(){
    TestDict();
    return 0;
}
