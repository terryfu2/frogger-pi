#include <stdlib.h>
#include <sys/mman.h>
#include "screen.h"
#include "framebuffer.h"
#include "game.h"
#include "images.h"

struct fbs framebufferstruct;

ScreenDim screen;

void initScreen(int width, int height) {
    screen.width = width;
    screen.height = height;
}

void drawScreen() {

    framebufferstruct = initFbInfo();

    Pixel *pixel;
    pixel = malloc(sizeof(Pixel));

    for (int y = 0; y < screen.height; y++) {
        for (int x = 0; x < screen.width; x++) {
            if(y == 0 || x == 0) {
                pixel->color = 0xF800;  //red for borders
                pixel->x = x;
                pixel->y = y;

            }else if(y == screen.height - 1 || x == screen.width - 1) {
                pixel->color = 0xF800;  //red for borders
                pixel->x = x;
                pixel->y = y;

            }else {
                pixel->color = 0x0; 
                pixel->x = x;
                pixel->y = y;

            }

            drawPixel(pixel);
        }
    }

    free(pixel);
    pixel = NULL;
    munmap(framebufferstruct.fptr, framebufferstruct.screenSize);
}

void drawObjects(GameState state, Pixel *pix) {

    for(int i = 0; i < sizeof(state.objects)/sizeof(state.objects[0]); i++) {
        int *imagePtr = (int *) frogFront.image_pixels;
        int j = 0;

        for(int y = 0; y < state.objects[i].yPos; y++) {
            for(int x = 0; x < state.objects[i].xPos; x++) {
                

                pix->color = imagePtr[j];
                pix->x = x;
                pix->y = y;
                j++;

            }
        }
    }
}


void drawPixel(Pixel *pixel){
	long int location = (pixel->x +framebufferstruct.xOff) * (framebufferstruct.bits/8) +
                       (pixel->y+framebufferstruct.yOff) * framebufferstruct.lineLength;
	*((unsigned short int*)(framebufferstruct.fptr + location)) = pixel->color;
}