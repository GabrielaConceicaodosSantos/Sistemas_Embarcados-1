//============================================================================
// Name        : Display_WiringPI.cpp
// Author      : Leonardo Amorim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <wiringPi.h>           //WiringPi headers
#include <lcd.h>                //LCD headers from WiringPi
#include <stdio.h>              //Needed for the printf function below
#include <stdlib.h>

//Pin numbers below are the WiringPi pin numbers

#define LCD_RS  8               //Register select pin
#define LCD_RW  9
#define LCD_E   7               //Enable Pin
#define LCD_D0	0
#define LCD_D1  2
#define LCD_D2  3
#define LCD_D3  12
#define LCD_D4  13               //Data pin 4
#define LCD_D5  14               //Data pin 5
#define LCD_D6  21               //Data pin 6
#define LCD_D7  22               //Data pin 7

int main() {
	//Usar GPIO 3 como modo WRITE no display
	system("echo 3 > /sys/class/gpio/export");
	system("echo out > /sys/class/gpio/gpio3/direction");
	system("echo 0 > /sys/class/gpio/gpio3/value");

	int lcd;                //Handle for LCD
	wiringPiSetup();        //Initialise WiringPi

	//Initialise LCD(int rows, int cols, int bits, int rs, int enable, int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7)
	if (lcd = lcdInit(2, 16, 8, LCD_RS, LCD_E, LCD_D0, LCD_D1, LCD_D2, LCD_D3,
			LCD_D4,
			LCD_D5, LCD_D6, LCD_D7)) {
		printf("lcd init failed! \n");
		return -1;
	}
	lcdPosition(lcd, 0, 0); //Position cursor on the first line in the first column
	lcdPuts(lcd, "HELLO WORLD"); //Print the text on the LCD at the current cursor position
	getchar();                      //Wait for key press
}
