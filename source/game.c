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
}

void setObject(GameObj object, int index) {
    game.objects[index] = object;
}

void newGame() {

    //base game state
    resetGameState();

    //add frog
    setObject(newFrog(20, 22), 0);

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