#pragma once

typedef struct {
    int color;
    int x, y;
}Pixel;

typedef struct {
    int width;
    int height;
}ScreenDim;

void initScreen(int width, int height);

void drawScreen();

void drawPixel(Pixel *pixel);