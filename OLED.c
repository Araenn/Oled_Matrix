#include <stdio.h>
#include <wiringPiSPI.h>
#include <wiringPi.h>
#include <time.h>
#include "SSD1306.h"

char value[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main(int argc, char **argv) {
	time_t now;
	struct tm *timenow;
	if (wiringPiSetup() < 0) return 1;
	printf("Programme OLED \n");
	SSD1306_begin();
	SSD1306_clear();
	while(1) {
		time(&now);
		timenow = localtime(&now);
		SSD1306_char3216(0, 16, value[timenow->tm_hour/10]);
		SSD1306_char3216(16, 16, value[timenow->tm_hour%10]);
		SSD1306_char3216(32, 16, ':');
		SSD1306_char3216(48, 16, value[timenow->tm_min/10]);
		SSD1306_char3216(64, 16, value[timenow->tm_min%10]);
		SSD1306_char3216(80, 16, ':');
		SSD1306_char3216(96, 16, value[timenow->tm_sec/10]);
		SSD1306_char3216(112, 16, value[timenow->tm_sec%10]);
		SSD1306_display();
	}
	return 0;
}
