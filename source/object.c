#include "object.h"

GameObj newFrog(int x , int y) {
    GameObj frog;

    frog.xPos = x * 32;
    frog.yPos = y * 32;

    frog.size = 1;

    frog.xVel = 32;
    frog.yVel = 32;

    frog.sprite = frogFront;

    return frog;
}

GameObj newCar(int x, int y, int size, int direction) {
    GameObj car;

    car.xPos = x * 32;
    car.yPos = y * 32;

    car.size = size;

    if(direction == 0) {

        car.xVel = -32;

        //set sprite to left facing
        
    }else if(direction == 1) {

        car.xVel = 32;

        //set sprite to right facing

    }

    return car;
}

GameObj newLog(int x, int y, int size, int direction) {
    GameObj log;

    log.xPos = x;
    log.yPos = y;

    log.size = size;

    if(direction == 0) {

        log.xVel = -32;
        
    }else if(direction == 1) {

        log.xVel = 32;

    }

    return log;
}

