#pragma once

#include "object.h"

typedef struct {
     
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

void setGameMap();

void setObject(GameObj object, int index);

void setFrogX(GameState game, int increment);

void newGame();