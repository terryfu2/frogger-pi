#include "game.h"
#include "object.h"
#include <stdio.h>

GameState game;

GameState getGameState() {
    return game;
}

void resetGameState() { 
    game.score = 500;
    game.lives = 3;
    game.timeLeft = 100;
    game.stepsLeft = 30;
    game.winFlag = 0;
    game.loseFlag = 0;
    game.isPaused = 0;
}

void pauseGame() {
    game.isPaused = 1;
}

void unpauseGame() {
    game.isPaused = 0;
}

void setObject(GameObj object, int index) {
    game.objects[index] = object;
}

void newGame() {

    //base game state
    resetGameState();

    //add frog
    setObject(newFrog(20, 22), 0);

    //add cars
    setObject(newCar(20, 6, 3, 0), 1);

    setObject(newCar(20, 8, 3, 1), 2);

    setObject(newCar(20, 10, 1, 0), 3);

    setObject(newCar(20, 12, 1, 1), 4);

}

void moveFrog(int direction) {
    int up = 0;
    int down = 1;
    int left = 2;
    int right = 3;

    if(direction == up) {

        if(game.objects[0].yPos != 32) {
            game.objects[0].yPos -= game.objects[0].yVel;
        }

    }else if(direction == down) {
        
        if(game.objects[0].yPos != 22 * 32) {
            game.objects[0].yPos += game.objects[0].yVel;
        }

    }else if(direction == left) {

        if(game.objects[0].xPos != 32) {
            game.objects[0].xPos -= game.objects[0].xVel;
        }

    }else if(direction == right) {

        if(game.objects[0].xPos != 39 * 32) {
            game.objects[0].xPos += game.objects[0].xVel;
        }

    }
}

void tickCars() {
    for(int i = 1; i < sizeof(game.objects) / sizeof(game.objects[0]); i++) {

        if(game.objects[i].size == 1) {

            if(game.objects[i].xPos == 39 * 32 && game.objects[i].xVel > 0) {

                game.objects[i].xPos = 1 * 32;

            }else if(game.objects[i].xPos == 1 * 32 && game.objects[i].xVel < 0) {

                game.objects[i].xPos = 39 * 32;

            }else {
                game.objects[i].xPos += game.objects[i].xVel;
            }

        }else if(game.objects[i].size == 3) {

            if(game.objects[i].xPos == 38 * 32 && game.objects[i].xVel > 0) {

                game.objects[i].xPos = 2 * 32;

            }else if(game.objects[i].xPos == 2 * 32 && game.objects[i].xVel < 0) {

                game.objects[i].xPos = 38 * 32;

            }else {
                game.objects[i].xPos += game.objects[i].xVel;
            }
        }
    }
}