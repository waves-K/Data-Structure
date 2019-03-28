#include"Stack.h"

#define ROWS (6)
#define COLS (6)


// 0 表示墙
// 1 表示路
// 2 表示已经走过的地方


int maze[ROWS][COLS] = {
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 1, 1 },
    { 0, 0, 1, 0, 0, 0 },
    { 0, 0, 1, 1, 1, 0 },
    { 0, 0, 1, 0, 1, 1 },
    { 0, 0, 1, 0, 0, 0 },
};

// 打印迷宫
void PrintMaze(int maze[ROWS][COLS]);

// 判断是否时出口
// 是就返回 1，不是就返回 0
int IsExit(Position pos){
    return pos.y == COLS - 1 ? 1 : 0;
}

// 判断这个点能不能通过
// 能 返回 1，不能 返回 0
int IsAccess(int maze[ROWS][COLS], Position pos){
    // 判断 pos 不能越界
    if(pos.x < 0 || pos.x >= ROWS || pos.y < 0 || pos.y >= ROWS){
        return 0;
    }
    return maze[pos.x][pos.y] == 1 ? 1 : 0;
}

void GoMaze(int maze[ROWS][COLS], Position entry){
    Stack stack;
    StackInit(&stack);
    Position pos = entry;   // 当前小人所处位置
    Position nextPos;       // 下个要走的位置

    while(1){
        maze[pos.x][pos.y] = 2;
        // 是出口，直接成功
        if(IsExit(pos)){
            PrintMaze(maze);
            printf("找到出口\n");
            printf("================\n");
        }

        // 不是出口，就按下面的顺序尝试
        // 左 -》上 -》右 -》下 
        nextPos = pos;
        nextPos.y -= 1;
        if(IsAccess(maze, nextPos)){
            StackPush(&stack, pos);
            // 往可走方向走一步，然后继续循环
            pos = nextPos;
            PrintMaze(maze);
            continue;
        }

        nextPos = pos;
        nextPos.x -= 1;

        if(IsAccess(maze, nextPos)){
            StackPush(&stack, pos);
            pos = nextPos;
            PrintMaze(maze);
            continue;
        }

        nextPos = pos;
        nextPos.y += 1;
        if(IsAccess(maze,nextPos)){
            StackPush(&stack, pos);
            pos = nextPos;
            PrintMaze(maze);
            continue;
        }

        nextPos = pos;
        nextPos.x += 1;
        if(IsAccess(maze, nextPos)){
            StackPush(&stack, pos);
            pos = nextPos;
            PrintMaze(maze);
            continue;
        }

        // 上 下 左 右 都不能走
        if(StackIsEmpty(&stack)){
            printf("迷宫探索结束\n");
            return;
        }

        // 回溯
        pos = StackTop(&stack);
        StackPop(&stack);
    }
}


void PrintMaze(int maze[ROWS][COLS]){
    int i, j;
    for(i = 0; i < ROWS; ++i){
        for(j = 0; j < COLS; ++j){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void TestMaze1(){
    Position entry = {5, 2};
    PrintMaze(maze);
    GoMaze(maze, entry);
    PrintMaze(maze);
}
