#pragma once

#include "object.h"


typedef struct {
    // instance of game map
 
    // positions of all objects, including frog
    GameObj objects[1];

    // score
    int score;

    // lives left
    int lives;

    // time left
    int timeLeft;

    // steps/moves left
    int stepsLeft;

    // win condition flag
    int winFlag;

    // lose condition flag
    int loseFlag;
    
}GameState;

GameState getGameState();

void resetGameState();

void setObject(GameObj object, int index);

void newGame();