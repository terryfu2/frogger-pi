#include "game.h"
#include "object.h"
#include <stdio.h>

GameState game;
int hit;

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

int getFrogX() {
    return game.objects[0].xPos;
}

int getFrogY() {
    return game.objects[0].yPos;
}

void moveFrog(int direction) {
    if(!game.isPaused) {
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
            }else {
                hitFrog();
            }

        }else if(direction == right) {

            if(game.objects[0].xPos != 39 * 32) {
                game.objects[0].xPos += game.objects[0].xVel;
            }else {
                hitFrog();
            }

        }
    }
}

void tickCars() {
    for(int i = 1; i < sizeof(game.objects) / sizeof(game.objects[0]); i++) {

        if(game.objects[i].size == 1) {     //tick small cars

            if(game.objects[i].xPos == 39 * 32 && game.objects[i].xVel > 0) {

                game.objects[i].xPos = 1 * 32;

            }else if(game.objects[i].xPos == 1 * 32 && game.objects[i].xVel < 0) {

                game.objects[i].xPos = 39 * 32;

            }else {
                game.objects[i].xPos += game.objects[i].xVel;
            }

        }else if(game.objects[i].size == 3) {       //tick large cars

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

void hitFrog(){
    hit++;
}

void checkCollision() {

    if(hit > 0) {
        hit = 0;

        //set frog back to start
        game.objects[0].xPos = 20 * 32;
        game.objects[0].yPos = 22 * 32;
    }

    for(int i = 1; i < sizeof(game.objects) / sizeof(game.objects[0]); i++) {

        // for small size obstacles
        if(game.objects[i].size == 1) {
            if(game.objects[i].xPos == getFrogX() && game.objects[i].yPos == getFrogY()) {
                hitFrog();
                continue;
            }
        }
        // for large size obstacles
        if(game.objects[i].size == 3) {
            if((game.objects[i].xPos == getFrogX() || game.objects[i].xPos + 32 == getFrogX() || game.objects[i].xPos - 32 == getFrogX()) && game.objects[i].yPos == getFrogY()) {
                hitFrog();
                continue;
            }
        }
    }
}

void tickGame() {
    if(!game.isPaused) {
        tickCars();
        checkCollision();
    }
}