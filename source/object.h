#pragma once

#include "images.h"

typedef struct {
    int xPos, yPos;

    int xVel, yVel;

    int xAcc, yAcc;

    image sprite;

}GameObj;

GameObj newFrog();