#ifndef INPUTARROW_H_INCLUDED
#define INPUTARROW_H_INCLUDED

#include "Engine.h"
#include "Input.h"
#include <conio.h>


class InputArrow : public Input {
public:
    int newX,newY;

   virtual void MovePlayer(int& playerX, int& playerY,  char** map, int width, int height, int& score);
    InputArrow(const InputArrow& re);
    InputArrow& operator=(const InputArrow& re);
    InputArrow(){}
    ~InputArrow(){}
};

#endif // INPUTARROW_H_INCLUDED
