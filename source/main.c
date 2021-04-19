#include "snes.h"
#include "screen.h"

#include <stdio.h>

int main() {

    initSNES();
    initScreen(720, 720);

    while(!getShouldClose()) {
        Read_Snes();
        Print_Message();
        drawScreen();
    }

    printf("Exiting program\n");

    Wait(2000000);

    return 0;
}