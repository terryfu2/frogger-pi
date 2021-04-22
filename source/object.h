#pragma once

#include "images.h"


typedef struct ScreenCoord{
    //x pixel
    int x;

    //y pixel
    int y;

}ScreenCoord;

typedef struct {
    
    //int size; //how many grid spots does it take

    int xPos, yPos;

    int xVel, yVel;

    int xAcc, yAcc;

    image sprite;

}GameObj;

GameObj newFrog(int x, int y);
