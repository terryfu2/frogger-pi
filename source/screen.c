#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include "screen.h"
#include "framebuffer.h"
#include "game.h"
#include "menuimg.h"
#include "buttons.h"


#define WIDTH 1280
#define HEIGHT 720

struct fbs framebufferstruct;

int screenImage[WIDTH][HEIGHT];

void drawScreen() {

    framebufferstruct = initFbInfo();

    Pixel *pixel;
    pixel = malloc(sizeof(Pixel));

    //drawMenu();
    //drawStartButton(whiteStart);
    //drawEndButton(whiteQuit);
    //drawBackground();
    //drawFrog(getGameState());

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixel->color = screenImage[x][y];
            pixel->x = x;
            pixel->y = y;

            drawPixel(pixel);
        }
    }

    free(pixel);
    pixel = NULL;
    munmap(framebufferstruct.fptr, framebufferstruct.screenSize);
}
void drawMenu(){
   int *imagePtr = (int *) startMenu.image_pixels;

    int j = 0;

    for(int y = 0; y < startMenu.height; y++) {
        for(int x = 0; x < startMenu.width; x++) {

            //assign color value to corresponding pixel
            screenImage[x][y] = imagePtr[j];
            j++;
            if(y == 0 || x == 0) {
                screenImage[x][y] = 0xF800; //red for border

            }else if(y == HEIGHT - 1 || x == WIDTH - 1) {
                screenImage[x][y] = 0xF800; //red for border

            }

        }
    }

}
void drawStartButton(button currentButton){
    int *imagePtr = (int *) currentButton.image_pixels;

    int j = 0;

    for(int y = 450; y < currentButton.height + 450; y++) {
        for(int x = 540; x < currentButton.width + 540; x++) {

            //assign color value to corresponding pixel
            screenImage[x][y] = imagePtr[j];
            j++;

        }
    }
}
void drawEndButton(button currentButton){
    int *imagePtr = (int *) currentButton.image_pixels;

    int j = 0;

    for(int y = 550; y < currentButton.height + 550; y++) {
        for(int x = 540; x < currentButton.width + 540; x++) {

            //assign color value to corresponding pixel
            screenImage[x][y] = imagePtr[j];
            j++;

        }
    }
}
void drawBackground() {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {

            if(y == 0 || x == 0) {
                screenImage[x][y] = 0xF800; //red for border

            }else if(y == HEIGHT - 1 || x == WIDTH - 1) {
                screenImage[x][y] = 0xF800; //red for border

            }else {
                screenImage[x][y] = 0x0;

            }
        }
    }
}

void drawObjects(GameState state) {

    for(int i = 1; i < sizeof(state.objects)/sizeof(state.objects[0]); i++) {   //starts at index 1 because 0 is the frog
        //pointer to current object sprite
        int *imagePtr = (int *) state.objects[i].sprite.image_pixels;

        int j = 0;

        for(int y = state.objects[i].yPos; y < state.objects[i].sprite.height; y++) {
            for(int x = state.objects[i].xPos; x < state.objects[i].sprite.width; x++) {
                
                //assign color value to corresponding pixel
                screenImage[x][y] = imagePtr[j];
                j++;
            }
        }
    }
}

void drawFrog(GameState state) {

    //pointer to current object sprite (frog)
    int *imagePtr = (int *) state.objects[0].sprite.image_pixels;

    int j = 0;

    for(int y = state.objects[0].yPos; y < state.objects[0].yPos + state.objects[0].sprite.height; y++) {
        for(int x = state.objects[0].xPos; x < state.objects[0].xPos + state.objects[0].sprite.width; x++) {

            //assign color value to corresponding pixel
            screenImage[x][y] = imagePtr[j];
            j++;

        }
    }
}


void drawPixel(Pixel *pixel){
	long int location = (pixel->x +framebufferstruct.xOff) * (framebufferstruct.bits/8) +
                       (pixel->y+framebufferstruct.yOff) * framebufferstruct.lineLength;
	*((unsigned short int*)(framebufferstruct.fptr + location)) = pixel->color;
}