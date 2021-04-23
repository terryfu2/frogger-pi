#include "game.h"
#include "object.h"
#include <stdio.h>

GameState game;
int hit;

GameState getGameState() {
    return game;
}

//reset game to base state for restart
void resetGameState() { 
    game.score = 500;
    game.lives = 4;
    game.timeLeft = 120;
    game.stepsLeft = 99;
    game.winFlag = 0;
    game.loseFlag = 0;
    game.isPaused = 0;
}

//set pause flag to true
void pauseGame() {
    game.isPaused = 1;
}

//set pause flag to false
void unpauseGame() {
    game.isPaused = 0;
}

//create object in array
void setObject(GameObj object, int index) {
    game.objects[index] = object;
}

//create a newgame and frog
void newGame() {

    //base game state
    resetGameState();

    //add frog
    setObject(newFrog(20, 21), 0);

    //add cars
    setObject(newLog(20, 6, 3, 0), 1);

    setObject(newLog(20, 8, 3, 1), 2);

    // setObject(newCar(20, 10, 1, 0), 3);

    setObject(newWater(20, 10), 3);

    setObject(newCar(20, 12, 1, 1), 4);

}

int getFrogX() {
    return game.objects[0].xPos;
}

int getFrogY() {
    return game.objects[0].yPos;
}

void updateScore(){
    game.score = game.stepsLeft + game.timeLeft + game.lives * 100;
}
//move frog in given direction
void moveFrog(int direction) {
    if(!game.isPaused) {
        int up = 0;
        int down = 1;
        int left = 2;
        int right = 3;
        game.stepsLeft --;
        if(direction == up) {

            if(game.objects[0].yPos != 32) {
                game.objects[0].yPos -= game.objects[0].yVel;
            }

        }else if(direction == down) {
            
            if(game.objects[0].yPos != 22 * 32) {
                game.objects[0].yPos += game.objects[0].yVel;
            }

        }else if(direction == left) {

            if(getFrogX() - 32 > 8) {
                game.objects[0].xPos -= game.objects[0].xVel;
            }else {
                hitFrog();
            }

        }else if(direction == right) {

            if(getFrogX() + 32 < 1272) {
                game.objects[0].xPos += game.objects[0].xVel;
            }else {
                hitFrog();
            }

        }
    }
}

void tickCars() {
    for(int i = 1; i < sizeof(game.objects) / sizeof(game.objects[0]); i++) {

        if(game.objects[i].size == 1 && game.objects[i].type == 0) {     //tick small cars

            if(game.objects[i].xPos == 39 * 32 && game.objects[i].xVel > 0) {

                game.objects[i].xPos = 1 * 32;

            }else if(game.objects[i].xPos == 1 * 32 && game.objects[i].xVel < 0) {

                game.objects[i].xPos = 39 * 32;

            }else {
                game.objects[i].xPos += game.objects[i].xVel;
            }

        }else if(game.objects[i].size == 3 && game.objects[i].type == 0) {       //tick large cars

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

void tickLogs() {
    for(int i = 1; i < sizeof(game.objects) / sizeof(game.objects[0]); i++) {

        if(game.objects[i].size == 3 && game.objects[i].type == 1) {       //tick large logs

            if(game.objects[i].xPos == 38 * 32 && game.objects[i].xVel > 0) {

                game.objects[i].xPos = 2 * 32;

            }else if(game.objects[i].xPos == 2 * 32 && game.objects[i].xVel < 0) {

                game.objects[i].xPos = 38 * 32;

            }else {

                if(FrogOnLog(i)) {
                    game.objects[0].xPos += game.objects[i].xVel;
                }

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

        //decrement lives
        game.lives--;

        //set frog back to start
        game.objects[0].xPos = 20 * 32;
        game.objects[0].yPos = 22 * 32;
    }

    if(getFrogX() == 0 || getFrogX() == 39 * 32) {
        hitFrog();
    }

    for(int i = 1; i < sizeof(game.objects) / sizeof(game.objects[0]); i++) {

        // for small size obstacles
        if(game.objects[i].size == 1 && game.objects[i].type != 1) {
            if(game.objects[i].xPos == getFrogX() && game.objects[i].yPos == getFrogY()) {
                hitFrog();
                continue;
            }
        }
        // for large size obstacles
        if(game.objects[i].size == 3 && game.objects[i].type != 1) {
            if((game.objects[i].xPos == getFrogX() || game.objects[i].xPos + 32 == getFrogX() || game.objects[i].xPos - 32 == getFrogX()) && game.objects[i].yPos == getFrogY()) {
                hitFrog();
                continue;
            }
        }
    }
}

int FrogOnLog(int log) {
    int onLog = 0;

    if((game.objects[log].xPos == getFrogX() || game.objects[log].xPos + 32 == getFrogX() || game.objects[log].xPos - 32 == getFrogX()) && game.objects[log].yPos == getFrogY()) {
        onLog = 1;
    }

    return onLog;
}

void checkLoss() {
    if(game.lives == 0) {
        game.loseFlag = 1;
    }
    if(game.timeLeft == 0) {
        game.loseFlag = 1;
    }
    if(game.stepsLeft == 0) {
        game.loseFlag = 1;
    }
}
void quitGame(){
    game.loseFlag = 1;
}
void tickGame() {
    if(!game.isPaused) {
        tickCars();
        tickLogs();
        checkCollision();
        checkLoss();
    }
}