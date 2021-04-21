#include "game.h"
#include "object.h"

GameState game;

GameMap map;

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

void setGameMap() {

    int i = 0;

    for(int x = 0; x < sizeof(map.grid) / sizeof(map.grid[0]); x += 32) {

        int j = 0;

        for(int y = 0; y < sizeof(map.grid[0]) / sizeof(map.grid[0][0]); y += 32) {

            ScreenCoord temp = {x, y};
            map.grid[i][j] = temp;

            j++;

        }

        i++;
    }
}

void setObject(GameObj object, int index) {
    game.objects[index] = object;
}

void newGame() {
    //initialize the map
    setGameMap();

    //base game state
    resetGameState();

    //add frog
    setObject(newFrog(), 0);

}