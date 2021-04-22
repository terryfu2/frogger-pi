#pragma once
#include "game.h"
#include "halfscreens.h"

typedef struct {
    int color;
    int x, y;
}Pixel;

typedef struct {
    int width;
    int height;
}ScreenDim;

void drawScreen();

int drawMenu();

int drawHalf(halfscreen screenToPrint, int paused);

void drawStartButton();

void drawEndButton();

void drawBackground();

void drawObjects(GameState state);

void drawFrog(GameState state);

void drawGrid();

void drawPixel(Pixel *pixel);