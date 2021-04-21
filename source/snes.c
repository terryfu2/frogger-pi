#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "initGPIO.h"

//SNES offsets
#define CLK 11
#define LAT 9
#define DAT 10

//GPIO offsets
#define GPSET0  7
#define GPCLR0  10
#define GPLEV0  13

//clock
#define CLO_REG 0x7E003004

//base GPIO address
unsigned int *base;

//buttons
int buttons[16] = {1};

//if program should close
int shouldClose = 0;
int upPressed = 1;
int downPressed = 0;
int pressedA = 0;


void Init_GPIO(int line, int func) {
    *(base + ((line) / 10)) &= ~(7 << (((line) % 10) * 3));
        
    if(func == 1) {
        *(base + ((line) / 10)) |= (1 << (((line) % 10) * 3));
    }
}

void Write_Latch(int func) {
    if(func == 1) {
        base[GPSET0] = 1 << LAT;
    }else {
        base[GPCLR0] = 1 << LAT;
    }
}

void Write_Clock(int func) {
    if(func == 1) {
        base[GPSET0] = 1 << CLK;
    }else {
        base[GPCLR0] = 1 << CLK;
    }
}

int Read_Data() {
    int v = (base[GPLEV0] >> DAT) & 1;
    return v;
}

void Wait(int n) {
    usleep(n);
}

//from RPi 2 SNES
void Read_Snes() {
    Write_Clock(1);
    Write_Latch(1);
    Wait(12);               //signal to SNES to sample buttons
    Write_Latch(0);
    
    int i = 0;
    
    while(i <= 15) {        //start pulsing to read from SNES
        Wait(1800);         //original wait time was 6 micro seconds but a slower tick time feels better
        Write_Clock(0);
        Wait(1800);
        int d = Read_Data();
        buttons[i] = d;
        Write_Clock(1);
        i++;
    }
}
void readButton(){
    int i;
        
    for(i = 0; i <= sizeof(buttons); i++) {
        if(buttons[i] == 0) {
            switch(i) {
                case 0:
                    printf("You have pressed B\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 1:
                    printf("You have pressed Y\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 2:
                    printf("You have pressed Select\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 3:
                    printf("You have pressed Start\n\n");
                    shouldClose = 1;
                    break;
                case 4:
                    printf("You have pressed Joy-pad UP\n\n");
                    printf("Please press a button...\n\n");
                    upPressed = 1;
                    downPressed = 0;
                    break;
                case 5:
                    printf("You have pressed Joy-pad DOWN\n\n");
                    printf("Please press a button...\n\n");
                    downPressed = 1;
                    upPressed = 0;
                    break;
                case 6:
                    printf("You have pressed Joy-pad LEFT\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 7:
                    printf("You have pressed Joy-pad RIGHT\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 8:
                    printf("You have pressed A\n\n");
                    printf("Please press a button...\n\n");
                    pressedA = 1;
                    break;
                case 9:
                    printf("You have pressed X\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 10:
                    printf("You have pressed Left\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 11:
                    printf("You have pressed Right\n\n");
                    printf("Please press a button...\n\n");
                    break;
            }
        }
    }
}
void readGame() {
    int i;
        
    for(i = 0; i <= sizeof(buttons); i++) {
        if(buttons[i] == 0) {
            switch(i) {
                case 0:
                    printf("You have pressed B\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 1:
                    printf("You have pressed Y\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 2:
                    printf("You have pressed Select\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 3:
                    printf("You have pressed Start\n\n");
                    shouldClose = 1;
                    break;
                case 4:
                    printf("You have pressed Joy-pad UP\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 5:
                    printf("You have pressed Joy-pad DOWN\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 6:
                    printf("You have pressed Joy-pad LEFT\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 7:
                    printf("You have pressed Joy-pad RIGHT\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 8:
                    printf("You have pressed A\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 9:
                    printf("You have pressed X\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 10:
                    printf("You have pressed Left\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 11:
                    printf("You have pressed Right\n\n");
                    printf("Please press a button...\n\n");
                    break;
            }
        }
    }
}
void Print_Message() {
    int i;
        
    for(i = 0; i <= sizeof(buttons); i++) {
        if(buttons[i] == 0) {
            switch(i) {
                case 0:
                    printf("You have pressed B\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 1:
                    printf("You have pressed Y\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 2:
                    printf("You have pressed Select\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 3:
                    printf("You have pressed Start\n\n");
                    shouldClose = 1;
                    break;
                case 4:
                    printf("You have pressed Joy-pad UP\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 5:
                    printf("You have pressed Joy-pad DOWN\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 6:
                    printf("You have pressed Joy-pad LEFT\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 7:
                    printf("You have pressed Joy-pad RIGHT\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 8:
                    printf("You have pressed A\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 9:
                    printf("You have pressed X\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 10:
                    printf("You have pressed Left\n\n");
                    printf("Please press a button...\n\n");
                    break;
                case 11:
                    printf("You have pressed Right\n\n");
                    printf("Please press a button...\n\n");
                    break;
            }
        }
    }
}
 
void initSNES() {
    // get gpio pointer
    unsigned int *gpioPtr = getGPIOPtr(); 
    
    //set base
    base = gpioPtr;
    
    //initialize SNES
    Init_GPIO(CLK, 1);
    Init_GPIO(LAT, 1);
    Init_GPIO(DAT, 0);
}

int getShouldClose() {
    return shouldClose;
}
int getA(){
    return pressedA;
}
int getUp(){
    return upPressed;
}
int getDown(){
    return downPressed;
}
// int main()
// {
//     printf("Created by: Terry Fu and Matthew Low\n\n");

// 	// get gpio pointer
//     unsigned int *gpioPtr = getGPIOPtr(); 
    
//     //set base
//     base = gpioPtr;
    
//     //initialize SNES
//     Init_GPIO(CLK, 1);
//     Init_GPIO(LAT, 1);
//     Init_GPIO(DAT, 0);

//     printf("Please press a button...\n\n");
    
//     while(!shouldClose) {
//         Read_Snes();
//         Print_Message();
//     }
    
//     printf("Exiting program\n");
//     Wait(2000000);
    
//     return 0;
// }
