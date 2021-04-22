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

    int type; // 0 is car, 1 is log, 2 is water

    int xPos, yPos;

    int xVel, yVel;

    int xAcc, yAcc;

    int size; //how many grid spots does it take

    image sprite;

    largeimage largeSprite;

}GameObj;

GameObj newFrog(int x, int y);

GameObj newCar(int x, int y, int size, int direction);

GameObj newLog(int x, int y, int size, int direction);

GameObj newWater(int x, int y);