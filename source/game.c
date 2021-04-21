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
void setFrogX(GameState game, int increment){
    printf("%d",game.objects[0].xPos);
    game.objects[0].xPos =  game.objects[0].xPos+ increment;
}
void newGame() {
    
    //base game state
    resetGameState();

    //add frog
    setObject(newFrog(), 0);

}