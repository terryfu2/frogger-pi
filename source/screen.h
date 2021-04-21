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

void drawStartButton();

void drawEndButton();

void drawBackground();

void drawObjects(GameState state);

void drawFrog(GameState state);

void drawPixel(Pixel *pixel);