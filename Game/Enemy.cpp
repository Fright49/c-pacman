#include "enemy.h"
#include <cstdlib>
#include <ctime>


void Enemy::GenerateEnemies(char** map, int width, int height, Enemy* enemies) {
    srand(time(NULL));

    int currentEnemies = 0;

    while (currentEnemies < maxEnemies) {
        int x = rand() % width;
        int y = rand() % height;

        if (map[y][x] == ' ') {
            enemies[currentEnemies].x = x;
            enemies[currentEnemies].y = y;
            map[y][x] = 'E';
            currentEnemies++;
        }
    }
}

void Enemy::MoveEnemies(char** map, int width, int height, Enemy* enemies) {
    for (int i = 0; i < maxEnemies; i++) {
        int randomDirection = rand() % 4;

        int newX = enemies[i].x;
        int newY = enemies[i].y;

        switch (randomDirection) {
        case 0: // Góra
            newY--;
            break;
        case 1: // Dól
            newY++;
            break;
        case 2: // Lewo
            newX--;
            break;
        case 3: // Prawo
            newX++;
            break;
        }

        if (newX >= 0 && newX < width && newY >= 0 && newY < height && map[newY][newX] != char(219)&& map[newY][newX] != '#') {
            bool isAnotherEnemy = false;
            for (int j = 0; j < maxEnemies; j++) {
                if (j != i && newX == enemies[j].x && newY == enemies[j].y) {
                    isAnotherEnemy = true;
                    break;
                }
            }

            if (!isAnotherEnemy) {
                if (map[enemies[i].y][enemies[i].x] != '.') {
                    map[enemies[i].y][enemies[i].x] = ' ';
                }
                enemies[i].x = newX;
                enemies[i].y = newY;
                map[newY][newX] = 'E';
            }
        }
    }
}
