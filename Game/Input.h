#ifndef INPUT_H
#define INPUT_H
#include <conio.h>

class Input {
public:
    int newX,newY;
   virtual void MovePlayer(int& playerX, int& playerY,char** map, int width, int height, int& score);
    Input(const Input& re);
    Input& operator=(const Input& re);
    Input(){}
    ~Input(){}
};

#endif
