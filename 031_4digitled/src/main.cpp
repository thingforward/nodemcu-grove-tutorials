#include <Arduino.h>
#include <Wire.h>
#include <TM1637Display.h>

TM1637Display	display(D1, D2);

void setup() {
	display.setBrightness(7);
}

int value = 0;

void loop() {
	display.showNumberDec(value++, true);
	delay(200);
}
