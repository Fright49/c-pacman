#ifndef VIEWOTHER_H_INCLUDED
#define VIEWOTHER_H_INCLUDED

#include "Engine.h"


class ViewOther : public View{
public:
    void ClearScreen();
    void ShowGameOver();
    void ShowWinMessage();
   virtual void DrawMap(char** map, int &width, int &height, int &playerX, int &playerY, Enemy* enemies, int &score);
   virtual void RunGame();
    ViewOther(const ViewOther& re);
    ViewOther& operator=(const ViewOther& re);
    ViewOther(){}
    ~ViewOther(){}
};

#endif // VIEWOTHER_H_INCLUDED
