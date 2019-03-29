/*
 * fopen/fclose
 * 
 * getchar - 文件内读 -> fgetc 
 * putchar - 文件内写 -> fputc
 * 
 * printf - 文件内打印 -> fprintf
 * 
 */ 

#include<stdio.h>
#include<assert.h>

#if 0

/* ... *
 
1. /* ... */
2. /* ... * 9527
3. /* ... **/
#endif


#include<stdio.h>

// 状态
typedef  enum{
    CODE,       // 代码状态
    YU_DAO_XIE_GANG,    // 遇到 /
    C_COMMENT,          // C 风格注释
    CPP_COMMENT,        // C++ 风格注释
    YU_DAO_XING         // C 风格中遇到 *
}   State;

// GBK 编码 一个字符占两个字节

void Convert(FILE* pIn, FILE* pOut){
    // state 表示的是状态转换过程中的当前状态
    // CODE 表示的是初始状态
    State state = CODE;
    const char* state_desc[] = {
        "正常状态",
        "遇到 / ",
        "C 风格注释",
        "C++ 风格注释",
        "C 风格中遇到 * "
    };

    int ch;
    int nextCh;
    while(1){
        // 从文件中依次读一个字符
        ch = fgetc(pIn);

        // 如果文件到末尾，就退出整个循环
        // 处理读完文件的情况
        if(ch == EOF){
            break;
        }

        printf("读到字符：%c, 当前状态:%s --> ", (char)ch, state_desc[state]);
        // 根据当前状态 + 读到的字符，决定下一个状态
        switch(state){
            case CODE:
                if(ch == '/'){
                    state = YU_DAO_XIE_GANG;
                }
                fputc(ch, pOut);
                break;
            case YU_DAO_XIE_GANG:
                if(ch == '*'){
                    state = C_COMMENT;
                    fputc('/', pOut);
                }
                else if(ch == '/'){
                    state = CPP_COMMENT;
                    fputc(ch, pOut);
                }
                else{
                    state = CODE;
                    fputc(ch, pOut);
                }
                break;
            case C_COMMENT:
                if(ch == '*'){
                    state = YU_DAO_XING;
                }
                else{
                    fputc(ch, pOut);
                    if(ch == '\n'){
                        fprintf(pOut, "//");
                    }
                }
                break;
            case CPP_COMMENT:
                if(ch == '\n'){
                    state = CODE;
                }
                fputc(ch, pOut);
                break;
            case YU_DAO_XING:
                if(ch == '/'){
                    state = CODE;
                    nextCh = fgetc(pIn);
                    if(nextCh != '\n'){
                        fputc('\n', pOut);
                     }
                    ungetc(nextCh, pIn);
                }
                else if(ch != '*'){
                    state = C_COMMENT;
                    fputc('*', pOut);
                    fputc(ch, pOut);
                }
                else{
                   fputc('*', pOut); 
                }
                break;
        }

        printf("%s \n",state_desc[state]);
    }
}

int main(){
    // 相对路径，绝对路劲
    FILE* pIn = fopen("input.c", "r");
    if(pIn == NULL){
        perror("fopen input");
        return 1;
    }

    // a -> append
    FILE* pOut = fopen("output.c", "w");
    if(pOut == NULL){
        perror("fopen output");
        fclose(pIn);
        return 1;
    }

    // 尽量养成一个习惯:先打开的文件后关闭
    // 这样可以避免死锁
    

    fclose(pOut);
    fclose(pIn);
    return 0;
}


# if 0

//     /* int a */  -> // int a
//     /* *5 -> // *5
//     /* ** -> // // *

#endif 


