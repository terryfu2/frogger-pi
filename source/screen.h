#pragma once
#include "game.h"

typedef struct {
    int color;
    int x, y;
}Pixel;

typedef struct {
    int width;
    int height;
}ScreenDim;

void drawScreen();

void drawMenu();

void drawHalf();

void drawStartButton();

void drawEndButton();

void drawBackground();

void drawObjects(GameState state);

void drawFrog(GameState state);

void drawGrid();

void drawPixel(Pixel *pixel);