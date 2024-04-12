#ifndef ENGINE_H
#define ENGINE_H

#include "Enemy.h"
#include "Input.h"
#include "View.h"


class Engine {
private:
    int width;
    int height;
    int playerX;
    int playerY;
    Enemy enemies[4];
    char** map;
    int score;


public:
    void Klawiatura();
    Engine();
    ~Engine();
    void GenerateFruits();
    bool CheckWinCondition();
    void CleanUpMap();
    bool CheckEnemyCollision();
    void ValidMove(int& playerX, int& playerY, char** map, int width, int height, int& score,int newX,int newY);
        Input* xinput;
        friend class View;
        friend class ViewOther;



};

#endif
