#include"Stack.h"
#include"Stack.c"


void BracketMatch(const char* sequence, int size){
    Stack stack;
    StackInit(&stack);

    char ch;
    char leftBracket;

    for(int i = 0; i < size; ++i){
        ch = sequence[i];   // 存当前字符
        switch(ch){
            case '(':
            case '[':
            case '{':
                StackPush(&stack, (StackDatatype)ch);
                break;
                
            case ')':
            case ']':
            case '}':
                if(StackEmpty(&stack)){
                    printf("右括号多\n");
                    StackDestroy(&stack);
                    return;
                }
                leftBracket = (char)StackTop(&stack);
                StackPop(&stack);

                if(leftBracket == '(' && ch != ')'){
                    printf("不匹配\n");
                    return;
                }

                if(leftBracket == '[' && ch != ']'){
                    printf("不匹配\n");
                    return;
                }

                if(leftBracket == '{' && ch != '}'){
                    printf("不匹配\n");
                    return;
                }

            default:
                break;
        }
    }
    if(StackEmpty(&stack)){
        printf("左括号多\n");
        return;
    }

    printf("正常匹配\n");
}

