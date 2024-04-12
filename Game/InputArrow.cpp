#include "InputArrow.h"
#include "Engine.h"
#include <conio.h>
#include <iostream>





void InputArrow::MovePlayer(int& playerX, int& playerY,char** map, int width, int height, int& score) {
    Engine engine;
     newX = playerX;
     newY = playerY;
    char input;
    std::cin>>input;

    switch (input) {
    case 'i': // Poruszanie w góre
        newY = playerY - 1;
        break;
    case 'k': // Poruszanie w dól
        newY = playerY + 1;
        break;
    case 'j': // Poruszanie w lewo
        newX = playerX - 1;
        break;
    case 'l': // Poruszanie w prawo
        newX = playerX + 1;
        break;
    }
    engine.ValidMove(playerX,playerY,map,width,height,score,newX,newY);
}
