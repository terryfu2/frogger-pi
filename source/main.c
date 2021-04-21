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
    
    drawMenu();
    drawStartButton(whiteStart);
    drawEndButton(whiteQuit);
    while(!getShouldClose()) {

        // input
        Read_Snes();
        Print_Message();

        // update screen
        drawScreen();
    }

    printf("Exiting program\n");

    Wait(2000000);

    return 0;
}