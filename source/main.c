#include "snes.h"
#include "screen.h"

#include <stdio.h>

int main() {

    // initialize input
    initSNES();

    // initialize screen size
    initScreen(1280, 720);

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