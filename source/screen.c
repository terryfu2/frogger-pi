#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include "screen.h"
#include "framebuffer.h"
#include "game.h"
#include "menuimg.h"
#include "buttons.h"
#include "halfscreens.h"


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
void drawHalf(){
   int *imagePtr = (int *) gamePaused.image_pixels;

    int j = 0;

    for(int y = 200; y < gamePaused.height; y++) {
        for(int x = 300; x < gamePaused.width; x++) {

            //assign color value to corresponding pixel
            screenImage[x][y] = imagePtr[j];
            j++;
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

    for(int i = 1; i < sizeof(state.objects) / sizeof(state.objects[0]); i++) {   //starts at index 1 because 0 is the frog
        //pointer to current object sprite
        int *imagePtr = (int *) state.objects[i].sprite.image_pixels;

        int j = 0;

        int top = state.objects[i].yPos - (state.objects[i].sprite.height / 2);
        int bot = state.objects[i].yPos + (state.objects[i].sprite.height / 2);

        int left = state.objects[i].xPos - (state.objects[i].sprite.width / 2);
        int right = state.objects[i].xPos + (state.objects[i].sprite.width / 2);

        for(int y = top; y < bot; y++) {
            for(int x = left; x < right; x++) {
                
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

    int top = state.objects[0].yPos - (state.objects[0].sprite.height / 2);
    int bot = state.objects[0].yPos + (state.objects[0].sprite.height / 2);

    int left = state.objects[0].xPos - (state.objects[0].sprite.width / 2);
    int right = state.objects[0].xPos + (state.objects[0].sprite.width / 2);

    for(int y = top; y < bot; y++) {
        for(int x = left; x < right; x++) {

            //assign color value to corresponding pixel
            screenImage[x][y] = imagePtr[j];
            j++;

        }
    }
}

void drawGrid() {
    for(int y = 0; y < HEIGHT; y += 32) {
        for(int x = 0; x < WIDTH; x += 32) {

            screenImage[x][y] = 0xF800;

        }
    }
}


void drawPixel(Pixel *pixel){
	long int location = (pixel->x +framebufferstruct.xOff) * (framebufferstruct.bits/8) +
                       (pixel->y+framebufferstruct.yOff) * framebufferstruct.lineLength;
	*((unsigned short int*)(framebufferstruct.fptr + location)) = pixel->color;
}