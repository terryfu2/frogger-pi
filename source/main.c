#include "initGPIO.h"
#include "snes.h"
#include "framebuffer.h"

int main() {

    initSNES();

    while(!getShouldClose()) {
        Read_Snes();
        Print_Message();
    }

    printf("Exiting program\n");

    Wait(2000000);

    return 0;
}