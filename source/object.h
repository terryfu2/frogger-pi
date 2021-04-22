#pragma once

#include "images.h"
#include "largeimages.h"


typedef struct ScreenCoord{
    //x pixel
    int x;

    //y pixel
    int y;

}ScreenCoord;

typedef struct {

    int xPos, yPos;

    int xVel, yVel;

    int xAcc, yAcc;

    int size; //how many grid spots does it take

    image sprite;

    largeimage largeSprite;

}GameObj;

GameObj newFrog(int x, int y);
