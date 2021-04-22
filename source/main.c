#include "snes.h"
#include "screen.h"
#include "game.h"
#include "menuimg.h"
#include "buttons.h"
#include "halfscreens.h"


#include <stdio.h>


//main function
int main() {

    // initialize input
    initSNES();

    //start game
    newGame();

    //draw menu and allow user input - if gameloop == 0, play game
    int gameloop = drawMenu();

 
    //game loop
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
        drawObjects(getGameState());
        drawFrog(getGameState());
        
        //if start is pressed, open the pause menu
        if(getStart() == 1){
            drawHalf(gamePaused);
        }
        drawScreen();
    }
    drawHalf(winScreen);
    drawScreen();
    
    printf("Exiting program\n");

    //keeps terminal open for a bit
    Wait(2000000);

    return 0;
}