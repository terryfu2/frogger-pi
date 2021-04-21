#pragma once

#include "object.h"

typedef struct{
    //x pixel
    int x;

    //y pixel
    int y;

}ScreenCoord;

typedef struct {
    //grid of 32x32 cells
    ScreenCoord grid[39][22];

}GameMap;

typedef struct {
    // instance of game map
    GameMap map;
 
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

void newGame();