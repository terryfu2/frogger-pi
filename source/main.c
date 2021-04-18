#include "snes.h"
#include "screen.h"

#include <stdio.h>

int main() {

    initSNES();

    initScreen();

    while(!getShouldClose()) {
        Read_Snes();
        Print_Message();
    }

    printf("Exiting program\n");

    Wait(2000000);

    return 0;
}