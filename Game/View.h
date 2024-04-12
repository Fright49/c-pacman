#ifndef VIEW_H
#define VIEW_H

#include "Engine.h"


class View {
public:
    void ClearScreen();
    void ShowGameOver();
    void ShowWinMessage();
   virtual void DrawMap(char** map, int &width, int &height, int &playerX, int &playerY, Enemy* enemies, int &score);
   virtual void RunGame();
    View(const View& re);
    View& operator=(const View& re);
    View(){}
    ~View(){}

};

#endif
