#pragma once 

// 坐标系中的坐标
typedef struct Position{
    int x;
    int y;
}Position;

// 蛇的每个结点结构
typedef struct SnakeNode{
    Position data;
    struct SnakeNode* pNext;
}SnakeNode;

// 蛇的前进方向
typedef enum Direction{
    UP, DOWN, LEFT, RIGHT
}Direction;

// 定义蛇的结构体
typedef struct Snake{
    SnakeNode* pHead;       // 指向蛇头结点
    SnakeNode* pTail;       // 指向蛇尾结点(有问题)
    Direction direction;    // 蛇的前进方向
}Snake;


// 游戏结构本身
typedef struct Game{
    Snake        snake;             // 蛇
    Position     foodPosition;      // 食物坐标
    int          score;             // 当前得分
    int          scorePerFood;      // 每吃一个食物的得分
    int          sleepTime;         // 每次前进的间隔
}Game;
