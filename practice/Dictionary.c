/* 二叉搜索树应用
 * 判断一个单词是否拼写正确
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


typedef struct Word{
    char  word[20];
    struct Word *left;
    struct Word *right;
} Word;

int WordFind(const Word *root, char word[]){
    const Word *cur = root;
    int ret;
    while (cur != NULL) {
        ret = strncmp(word, cur->word, 20);
        if (ret == 0) {
            return 1;
        } else if (ret > 0) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return 0;
}

int WordInsert(Word **root, char word[]){
    int ret;
    if (*root == NULL) {
        Word *node = (Word *)malloc(sizeof(Word));
        strncpy(node->word, word, 20);
        node->left = node->right = NULL;
        *root = node;
        return 1;
    }
    ret = strncmp(word, (*root)->word, 20);
    if (ret == 0) {
        return 0;
    }
    if (ret < 0) {
        return WordInsert(&(*root)->left, word);
    } else {
        return WordInsert(&(*root)->right, word);
    }
}

int TestDict(){
    Word *dict = NULL;

    WordInsert(&dict, "Apple");
    WordInsert(&dict, "Banana");
    WordInsert(&dict, "Orange");
    WordInsert(&dict, "Watermelon");
    WordInsert(&dict, "Pinapple");
    WordInsert(&dict, "pear");

    char word[20];

    while (1) {
        scanf("%s", word);
        if(WordFind(dict, word) == 1) {
            printf("拼写正确\n");
        } else {
            printf("拼写错误\n");
        }
    }
}

int main(){
    TestDict();
    return 0;
}
