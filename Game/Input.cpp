#include "input.h"
#include "Engine.h"

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100

void Input::MovePlayer(int& playerX, int& playerY,char** map, int width, int height, int& score) {
    Engine engine;
     newX = playerX;
     newY = playerY;
     char input = _getch();

    switch (input) {
    case 'w': // Poruszanie w góre
        newY = playerY - 1;
        break;
    case 's': // Poruszanie w dól
        newY = playerY + 1;
        break;
    case 'a': // Poruszanie w lewo
        newX = playerX - 1;
        break;
    case 'd': // Poruszanie w prawo
        newX = playerX + 1;
        break;
    }
    engine.ValidMove(playerX,playerY,map,width,height,score,newX,newY);
}
