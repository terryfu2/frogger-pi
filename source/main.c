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

    //draw menu and allow user input
    int gameloop = drawMenu();

    while(gameloop == 0) {

        // input
        Read_Snes();
        readGame(getGameState());
        
        // update screen
        drawBackground();
        drawGrid();
        drawFrog(getGameState());
        //if start is pressed, open the pause menu
        if(getStart() == 1){
            drawHalf();
        }
        drawScreen();
    }

    printf("Exiting program\n");

    Wait(2000000);

    return 0;
}