#include "ViewOther.h"
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

void ViewOther::DrawMap(char** map, int &width, int &height, int &playerX, int &playerY, Enemy* enemies, int &score) {

    system("cls");

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            bool isEnemy = false;
            for (int i = 0; i < 4; i++) {
                if (x == enemies[i].x && y == enemies[i].y) {
                    isEnemy = true;
                    std::cout << 'W'; // Rysuj wroga
                    break;
                }
            }
            if (!isEnemy) {
                if (x == playerX && y == playerY) {
                    cout << 'G'; // Rysuj gracza
                } else {
                    cout << map[y][x]; // Rysuj plansz� z tablicy map
                }
            }
        }
        cout << endl;
    }

    cout << "Punkty: " << score << endl;
}

void ViewOther::RunGame() {
    Enemy enemy;
    Engine engine;
    Input input;
      ifstream file("map.txt");

    file >> engine.width >> engine.height;

    engine.map = new char*[engine.height];
for (int y = 0; y < engine.height; y++) {
        engine.map[y] = new char[engine.width];
        for (int x = 0; x < engine.width; x++) {
            char value;
            file >> value;
            if (value == '2') {
                engine.playerX = x;
                engine.playerY = y;
            }
            engine.map[y][x] = (value == '1') ? '#' : ' ';
        }
    }
    file.close();

    engine.GenerateFruits();
    enemy.GenerateEnemies(engine.map, engine.width, engine.height, engine.enemies);

    while (true) {
        DrawMap(engine.map, engine.width, engine.height, engine.playerX, engine.playerY, engine.enemies, engine.score);

        if (engine.CheckWinCondition()) {
            cout << "Gratulacje! Wygrales!" << endl;
            exit(0);
            break;
        }

        if (engine.CheckEnemyCollision()) {
            cout << "Koniec gry!" << endl;
            exit(0);
            break;
        }

       // char userInput = _getch();
               engine.Klawiatura();

        //input.MovePlayer(engine.playerX, engine.playerY, userInput, engine.map, engine.width, engine.height, engine.score);
        enemy.MoveEnemies(engine.map, engine.width, engine.height, engine.enemies);
    }

    engine.CleanUpMap();
}
