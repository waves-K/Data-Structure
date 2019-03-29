#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>
#include"View.h"

// 坐标的转化
// 游戏的坐标 转换 光标的坐标

// 移动光标
void Move(int X, int Y){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;

    coord.X = X;
    coord.Y = Y;
    SetConsoleCursorPosition(hStdout, coord);
}

// width 和 height 指的是游戏内的坐标
void PrintWall(int width, int height){
    int i;

    // 上边
    Move(0, 0);
    for(i = 0; i < width + 2; ++i){
        printf("█");
    }

    // 下边
    Move(0, height + 1);
    for(i = 0; i < width + 2; ++i){
        printf("█");
    }

    // 左边
    for(i = 0; i < height; ++i){
        Move(0, i + 1);
        printf("█");
    }

    // 右边
    for(i = 0; i < height; ++i){
        Move(2*(width + 1), i + 1);
        printf("█");
    }
}


// 打印食物
void PrintFood(Position food){
    Move(2*(food.x + 1), food.y + 1);
    printf("¤");
}


void PrintSnakeBlock(Position pos){
    Move(2*(pos.x + 1), pos.y + 1);
    printf("◎");
}

// 擦除一格
void CleanBlock(Position pos){
    Move(2*(pos.x + 1), pos.y + 1);
    printf("  ");
}

// 打印一格蛇
void PrintSnake(Snake* pSnake){
    SnakeNode* pNode;
    pNode = pSnake->pHead;

    while(pNode != NULL){
        PrintSnakeBlock(pNode->data);
        pNode = pNode->pNext;
    }
}


// 打印死亡信息
void PrintDeathMessage(int width, int height){
    Move(0, height + 2);
    printf("Game Over");
}

void PrintWelcome(){
    printf("欢迎游戏\n");
    system("pause");
    system("cls");
}
