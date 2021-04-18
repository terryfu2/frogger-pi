#pragma once

typedef struct {
    int color;
    int x, y;
}Pixel;

void initScreen();

void drawPixel(Pixel *pixel);