#include "engine.h"
#include <fstream>
#include <ctime>
#include <iostream>
#include "InputArrow.h"
#include "Input.h"



Engine::Engine() {
    width = 0;
    height = 0;
    playerX = 0;
    playerY = 0;
    map = nullptr;
    score = 0;
    xinput= new Input();
    //xinput= new InputArrow();
}

Engine::~Engine() {
    CleanUpMap();
    if(xinput){delete xinput;}
}





void Engine::GenerateFruits() {
    srand((time(NULL)));

    int maxFruits = (width * height) / 10;
    int currentFruits = 0;

    while (currentFruits < maxFruits) {
        int x = rand() % width;
        int y = rand() % height;

        if (map[y][x] == ' ') {
            map[y][x] = '.';
            currentFruits++;
        }
    }
}

bool Engine::CheckWinCondition() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (map[y][x] == '.') {
                return false;
            }
        }
    }
    return true;
}

void Engine::CleanUpMap() {
    if (map != nullptr) {

        delete[] map;
        map = nullptr;
    }
}

bool Engine::CheckEnemyCollision() {
    for (int i = 0; i < 4; i++) {
        int distanceX = abs(playerX - enemies[i].x);
        int distanceY = abs(playerY - enemies[i].y);

        if ((distanceX == 1 && distanceY == 0) || (distanceX == 0 && distanceY == 1)|| (playerX == enemies[i].x && playerY == enemies[i].y)) {
            return true; // Przeciwnik jest obok gracza w pionie lub poziomie
        }
    }
    return false; // Żaden przeciwnik nie jest obok gracza
}
void Engine::ValidMove(int& playerX, int& playerY, char** map, int width, int height, int& score,int newX,int newY){
 if (newX >= 0 && newX < width && newY >= 0 && newY < height && map[newY][newX] != char(219) && map[newY][newX] != '#') {
        // Przemieszczenie gracza
        if (map[newY][newX] == '.') {
            score++;
            map[newY][newX] = ' ';
        }
        map[playerY][playerX] = ' ';
        playerX = newX;
        playerY = newY;
        map[playerY][playerX] = 'P';
    }
}

void Engine::Klawiatura(){


    xinput->MovePlayer(playerX,playerY,map,width,height,score);


}
