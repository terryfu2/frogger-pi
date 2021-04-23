#pragma once

#include "object.h"

typedef struct {

    //river bounds
    int rStart;

    int rEnd;
     
    // positions of all objects, including frog
    GameObj objects[15];

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

    // pause flag
    int isPaused;
    
}GameState;

GameState getGameState();

void resetGameState();

void pauseGame();

void unpauseGame();

void setObject(GameObj object, int index);

void newGame();

int getFrogX();

int getFrogY();

void updateScore();

void moveFrog(int direction);

void tickCars();

void tickLogs();

void hitFrog();

void checkCollision();

int FrogOnLog(int log);

void checkLoss();

void quitGame();

void tickGame();

void makeRiver(int start, int end);

void startTime();

void* tickTime();