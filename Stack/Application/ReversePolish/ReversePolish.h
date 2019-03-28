// 逆波兰表达式


#include"Stack.h"
#include"Stack.c"

typedef enum{
    OPERAND,    // 操作数类型
    OPERTOR     // 操作符类型
}Type;

typedef enum{
    ADD,
    SUB,
    MUL,
    DIV
}Opertor;

typedef struct{
    Type type;
    int operand;        // 操作数
    Opertor opertor;    // 操作符
}Element;

int ReversePolishNoTion(Element expression[], int size){
    Stack stack;
    StackInit(&stack);
    int op1, op2;
    double result;
    for(int i = 0; i < size; ++i){
        Element e = expression[i];

        switch(e.type){
            case OPERAND:
                StackPush(&stack, e.operand);
                break;
            case OPERTOR:
                switch(e.opertor){
                    case ADD:
                        // 因为加法是二元操作符，所以从栈中取两个操作数出来
                        op1 = StackTop(&stack);
                        StackPop(&stack);

                        op2 = StackTop(&stack);
                        StackPop(&stack);

                        result = op1 + op2;
                        // 结果也需要压栈
                        StackPush(&stack, result);
                        break;

                    case SUB:
                        op1 = StackTop(&stack);
                        StackPop(&stack);

                        op2 = StackTop(&stack);
                        StackPop(&stack);

                        result = op1 - op2;

                        StackPush(&stack, result);
                        break;

                    case MUL:
                        op1 = StackTop(&stack);
                        StackPop(&stack);

                        op2 = StackTop(&stack);
                        StackPop(&stack);

                        result = op1 * op2;

                        StackPush(&stack, result);
                        break;

                    case DIV:
                        op1 = StackTop(&stack);
                        StackPop(&stack);

                        op2 = StackTop(&stack);
                        StackPop(&stack);

                        result = op1 / op2;

                        StackPush(&stack, result);
                        break;
                    default:
                        assert(0);  // 不应该出现
                }
                break;
            default:
                assert(0);  // 不应该出现
        }
    }
    assert(StackSize(&stack) == 1);
    result = StackTop(&stack);

    return result;
}


void TestRPN(){
    Element expression[] = {
        {
            OPERAND,
            1,
            ADD     // 这个其实没用，随便写
        },
        {
            OPERAND,
            2,
            SUB
        },
        {
            OPERTOR,
            -1,     // 这个其实没用，可以随便写
            ADD
        },
        {
            OPERAND,
            3,
            SUB
        },
        {
            OPERTOR,
            -1,
            ADD
        }
    };

    int result = ReversePolishNoTion(expression, 5);
    
    printf("result = %d \n", result);
}

