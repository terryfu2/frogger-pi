#include "object.h"

struct ScreenCoord;

void updateObject() {

}

void drawObject() {

}

void initObject() {
    
}

GameObj newFrog(ScreenCoord coord) {
    GameObj frog;

    frog.xPos = coord.x;
    frog.yPos = coord.y;

    frog.sprite = frogFront;

    return frog;
}