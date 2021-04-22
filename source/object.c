#include "object.h"

GameObj newFrog(int x , int y) {
    GameObj frog;

    frog.xPos = x * 32;
    frog.yPos = y * 32;

    //frog.size = 1;

    frog.xVel = 32;
    frog.yVel = 32;

    frog.sprite = frogFront;

    return frog;
}

GameObj newCar(int x, int y, int size, int direction) {
    GameObj car;

    car.xPos = x * 32;
    car.yPos = y * 32;

    //car.size = size;

    if(direction == 0) {

    }else {
        
    }

    return car;
}

GameObj newLog() {

}

