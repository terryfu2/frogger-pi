#include "snes.h"
#include "screen.h"
#include "game.h"
#include "menuimg.h"
#include "buttons.h"


#include <stdio.h>



int main() {

    // initialize input
    initSNES();

    //start game
    newGame();

    //draw menu and allow user movement
    drawMenu();
    int up;
    while(getA() != 1){
        up = getUp();

        if(up == 1){
            drawStartButton(whiteStart);
            drawEndButton(blackQuit);

        }
        else{
            drawStartButton(blackStart);
            drawEndButton(whiteQuit);

        }
       
        Read_Snes();
        readButton();
        drawScreen();
    }
    int gameloop = 1;
    if(up == 1){
        gameloop = 0;
    }
    
    while(gameloop == 0) {

        // input
        Read_Snes();
        readGame(getGameState());

        // update screen
        drawBackground();
        //drawFrog(getGameState());
        drawScreen();
    }

    printf("Exiting program\n");

    Wait(2000000);

    return 0;
}