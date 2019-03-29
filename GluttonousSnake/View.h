#pragma once 

#include"Types.h"
// width 和 height 指的是游戏内的坐标
void PrintWall(int width, int height);

// 打印食物
void PrintFood(Position food);

// 擦除一格
void CleanBlock(Position pos);

// 打印一格蛇
void PrintSnakeBlock(Position pos);

// 打印蛇
void PrintSnake(Snake* pSnake);

// 打印死亡信息
void PrintDeathMessage(int width, int height);
