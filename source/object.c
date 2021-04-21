#include "object.h"


void updateObject() {

}

void drawObject() {

}

void initObject() {
    
}

GameObj newFrog(int x , int y) {
    GameObj frog;

    frog.xPos = x * 32;
    frog.yPos = y * 32;

    frog.xVel = 32;
    frog.yVel = 32;

    frog.sprite = frogFront;

    return frog;
}