#include "snes.h"
#include "screen.h"
#include "game.h"
#include "menuimg.h"
#include "buttons.h"
#include "halfscreens.h"


#include <stdio.h>


void gameLoop(int runMenu){
    resetStart();
    int gameloop;
    //game loop
    if(runMenu == 1){
        gameloop = drawMenu();
    }else{
        gameloop = 0;
    }
    while(gameloop == 0) {

        // if loss, exit loop
        if(getGameState().loseFlag) {
            break;
        }

        // input
        Read_Snes();
        readGame(getGameState());
        
        // update objects
        tickGame();

        // update screen
        drawBackground();
        drawGrid();
        drawRiver(getGameState());
        drawObjects(getGameState());
        drawFrog(getGameState());

        //draw currents
        drawLives(getGameState().lives);
        drawSteps(getGameState().stepsLeft);
        updateScore();
        drawScore(getGameState().score);
        drawTime(getGameState().timeLeft);
        
        //if start is pressed, open the pause menu
        if(getStart() == 1){
            int check = drawHalf(gamePaused,1);
            if(check ==1){
                return;
            }
        }
        drawScreen();
    }
}

//main function
int main() {

    // initialize input
    initSNES();

    //start game
    newGame();

    //draw menu and allow user input - if gameloop == 0, play game
    

    gameLoop(1);
    
    drawHalf(lossScreen,0);
    drawScreen();
    
    printf("Exiting program\n");

    //keeps terminal open for a bit
    Wait(2000000);
    
    return 0;
}