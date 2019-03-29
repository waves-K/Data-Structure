#include"Types.h"
#include"Game.c"
#include<time.h>

int main(){
    srand((unsigned)time(NULL));

    system("mode con cols=60 lines=31");

    PrintWelcome();

    PrintWall(WIDTH, HEIGHT);

    GameRun();

    PrintDeathMessage(WIDTH, HEIGHT);

    return 0;
}
