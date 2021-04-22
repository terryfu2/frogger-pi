#include "object.h"

//frog object
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

//car object
GameObj newCar(int x, int y, int size, int direction) {
    GameObj car;

    car.type = 0;

    car.xPos = x * 32;
    car.yPos = y * 32;

    car.size = size;

    if(direction == 0) {

        car.xVel = -16;
        
        if(size == 1) {
            // small sprite
            car.sprite = smallCarLeft;

        }else if(size == 2) {
            // medium sprite

        }else if(size == 3) {
            // large sprite
            car.largeSprite = largeCarLeft;

        }
        
    }else if(direction == 1) {

        car.xVel = 16;

        if(size == 1) {
            // small sprite
            car.sprite = smallCarRight;
            
        }else if(size == 2) {
            // medium sprite

        }else if(size == 3) {
            // large sprite
            car.largeSprite = largeCarRight;

        }
    }

    return car;
}

//log object
GameObj newLog(int x, int y, int size, int direction) {
    GameObj log;

    log.type = 1;

    log.xPos = x * 32;
    log.yPos = y * 32;

    log.size = size;

    if(direction == 0) {

        log.xVel = -8;
        
    }else if(direction == 1) {

        log.xVel = 8;

    }

    log.largeSprite = largeLog;

    return log;
}

GameObj newWater(int x, int y) {
    GameObj wet;

    wet.type = 2;

    wet.xPos = x * 32;
    wet.yPos = y * 32;

    wet.size = 1;

    wet.sprite = water;

    return wet;
}

