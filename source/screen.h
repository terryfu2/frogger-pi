#pragma once
#include "game.h"
#include "halfscreens.h"
#include "numbers.h"

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

void drawLives(int lives);

void drawSteps(int steps);

number getNumber(int num);

int drawHalf(halfscreen screenToPrint, int paused);

void drawStartButton();

void drawEndButton();

void drawBackground();

void drawObjects(GameState state);

void drawFrog(GameState state);

void drawGrid();

void drawPixel(Pixel *pixel);