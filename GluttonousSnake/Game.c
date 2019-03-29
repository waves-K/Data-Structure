#include"Types.h"
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
#include"View.h"
#include<unistd.h>

#define WIDTH  (28)
#define HEIGHT (27)

// 初始化蛇
void SnakeInit(Snake* pSnake){
    // 1.蛇的身子(放 3 个数据到队列)
    int i;
    int x, y;
    Position pos;
    SnakeNode* pNode;

    pSnake->pHead = pSnake->pTail = NULL;
    
    // (5,5)[尾巴] (6,5)    (7,5)[头]
    for(i = 0; i < 3; ++i){
        x = 5 + i;
        y = 5;
        pos.x = x;
        pos.y = y;

        pNode = (SnakeNode*)malloc(sizeof(SnakeNode));
        assert(pNode);
        pNode->data = pos;

        pNode->pNext = pSnake->pHead;
        pSnake->pHead = pNode;
    }

    pSnake->pTail = pSnake->pHead->pNext->pNext;

    // 2.蛇的方向
    pSnake->direction = RIGHT; 
}

    // IsOverlapSnake 自己实现的函数，返回 1 表示和蛇重叠，否则不重叠
int IsOverlapSnake(int x, int y, Snake* pSnake){
    SnakeNode* pNode;
    pNode = pSnake->pHead;
    while(pNode != NULL){
        if(pNode->data.x == x && pNode->data.y == y){
            return 1;
        }

        pNode = pNode->pNext;
    }

    return 0;
}

// 生成食物
void GenerateFood(Position* pFood, Snake* pSnake, int width, int height){
    // 1.必须在边界以内
    // 2.不能和蛇重叠
    // 3.随机

    int x, y;

    do{

        x = rand() % width;
        y = rand() % height;
    }while(IsOverlapSnake(x, y, pSnake));

    // 满足上面的三个条件了
    pFood->x = x;
    pFood->y = y;
}

// 游戏初始化
void GameInit(Game* pGame){
    // 初始化蛇
    SnakeInit(&(pGame->snake));
    // 生成食物
    GenerateFood(&(pGame->foodPosition), &(pGame->snake), WIDTH, HEIGHT);
    // 基本数据
    pGame->score = 0;
    pGame->scorePerFood = 10;
    pGame->sleepTime = 300;
}

Position GetNextPosition(Snake* pSnake){
                    // Snake  SnakeNode  Position
    Position nextPos = pSnake->pHead->data;

    switch(pSnake->direction){
        case UP:
            nextPos.y -= 1;
            break;
        case DOWN:
            nextPos.y += 1;
            break;
        case LEFT:
            nextPos.x -= 1;
            break;
        case RIGHT:
            nextPos.x += 1;
            break;
    }

    return nextPos;
}

// 在蛇的头上增加一个坐标 nextPos 表示蛇头前进一步
void SnakeAddHead(Snake* pSnake, Position nextPos){
    SnakeNode* pNode = (SnakeNode*)malloc(sizeof(SnakeNode));
    assert(pNode);

    pNode->data = nextPos;
    pNode->pNext = pSnake->pHead;
    pSnake->pHead = pNode;

    PrintSnakeBlock(nextPos);
}

// 在蛇的尾巴上删除一个坐标，表示蛇尾前进一步
// 注明: pTail 暂时没用上
void SnakeRemoveTail(Snake* pSnake){
    SnakeNode* pNode;
    pNode = pSnake->pHead;
    while(pNode->pNext->pNext != NULL){
        pNode = pNode->pNext;
    }

    CleanBlock(pNode->pNext->data);
    free(pNode->pNext);
    pNode->pNext = NULL;
}

// 判断蛇是否吃到食物，吃到返回 1，没吃到返回 0
int IsEatFood(Position nextPos, Position foodPos){
    return nextPos.x == foodPos.x && nextPos.y == foodPos.y;
}

// 是否撞墙，是返回 1 不是返回 0
int IsKilledByWall(Position nextPos, int width, int height){
    if(nextPos.x < 0){
        return 1;
    }
    
    if(nextPos.x >= width){
        return 1;
    }

    if(nextPos.y < 0){
        return 1;
    }

    if(nextPos.y >= height){
        return 1;
    }

    return 0;
}

// 是否撞到自己，是返回 1 不是返回 0
int IsSuicide(Snake* pSnake){
    Position head = pSnake->pHead->data;
    SnakeNode* pNode;
    pNode = pSnake->pHead->pNext;

    while(pNode != NULL){
        if(head.x == pNode->data.x && head.y == pNode->data.y){
            return 1;
        }
        pNode = pNode->pNext;
    }
    return 0;
}

void Pause(){
    while(1){
        if(GetAsyncKeyState(VK_SPACE)){
            break;
        }
        sleep(300);
    }
}

int GameRun(){
    Position nextPos;

    // 初始化工作
    //  1.Game 
    //      Snake(蛇)
    //      生成食物
    //      基本数据(得分...)
    Game    game;
    GameInit(&game);
    PrintFood(game.foodPosition);
    PrintSnake(&(game.snake));

    while(1){
        // 游戏结束
        //  1.撞墙(被动)
        //  2.撞自己(被动)
        //  3.ESC 主动
        
        // 根据判断方向
        if(GetAsyncKeyState(VK_UP) && game.snake.direction != DOWN){
            game.snake.direction = UP;
        }
        else if(GetAsyncKeyState(VK_DOWN) && game.snake.direction != UP){
            game.snake.direction = DOWN;
        }
        else if(GetAsyncKeyState(VK_LEFt) && game.snake.direction != RIGHT){
            game.snake.direction = LEFT;
        }
        else if(GetAsyncKeyState(VK_RIGHT) && game.snake.direction != LEFT){
            game.snake.direction = RIGHT;
        }
        else if(GetAsyncKeyState(VK_SPACE)){
            Pause();
        }
        else if(GetAsyncKeyState(VK_ESCAPE)){
            break;
        }

        // 下个格子坐标是什么？
        nextPos = GetNextPosition(&(game.snake));

        // 判断蛇是否吃到食物
        if(IsEatFood(nextPos, game.foodPosition)){
        SnakeAddHead(&(game.snake), nextPos);
        GenerateFood(&(game.foodPosition), &(game.snake), WIDTH, HEIGHT);
        PrintFood(game.foodPosition);
        game.score += game.scorePerFood;
        }
        else{
        SnakeRemoveTail(&(game.snake));
        SnakeAddHead(&(game.snake), nextPos);
        }
        // 1.蛇会前进(蛇没吃到食物)
        // ** 2.如果按方向键了，蛇能改变方向
        // 3.可能吃到食物
        //      1.增长
        //      2.重新生成食物
        //      3.加分
        
        // 是否撞墙
        if(IsKilledByWall(nextPos, WIDTH, HEIGHT)){
            break;
        }

        // 是否撞到自己
        if(IsSuicide(&(game.snake))){
            break;
        }
        Sleep(game.sleepTime);
        break;
    }
}
