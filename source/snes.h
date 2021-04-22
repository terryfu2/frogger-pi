#pragma once

void Init_GPIO(int line, int func);

void Write_Latch(int func);

void Write_Clock(int func);

int Read_Data();

void Wait(int n);

void Read_Snes();

void readGame();

void readButton();

void readPause();

void Print_Message();

void initSNES();

int getShouldClose();

int getA();

int getUp();

int getDown();

int getStart();

int getCheck();

int getPause();

void resetMovement();

void resetStart();

void resetPause();
