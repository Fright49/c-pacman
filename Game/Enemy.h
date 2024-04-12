#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    int x;
    int y;
    int maxEnemies = 4;


    void GenerateEnemies(char** map, int width, int height, Enemy* enemies);
    void MoveEnemies(char** map, int width, int height, Enemy* enemies);
    Enemy(const Enemy& re);
    Enemy& operator=(const Enemy& re);
    Enemy(){}
    ~Enemy(){}

};

#endif
