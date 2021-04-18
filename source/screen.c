#include <stdlib.h>
#include <sys/mman.h>
#include "screen.h"
#include "framebuffer.h"

struct fbs framebufferstruct;

void initScreen() {

    framebufferstruct = initFbInfo();

    Pixel *pixel;
    pixel = malloc(sizeof(Pixel));

    for (int y = 0; y < 720; y++) {
        for (int x = 0; x < 1280; x++) {
            pixel->color = 0xF800; // red pixel
            pixel->x = x;
            pixel->y = y;

            drawPixel(pixel);
        }
    }

    free(pixel);
    pixel = NULL;
    munmap(framebufferstruct.fptr, framebufferstruct.screenSize);
}

void drawPixel(Pixel *pixel){
	long int location = (pixel->x +framebufferstruct.xOff) * (framebufferstruct.bits/8) +
                       (pixel->y+framebufferstruct.yOff) * framebufferstruct.lineLength;
	*((unsigned short int*)(framebufferstruct.fptr + location)) = pixel->color;
}