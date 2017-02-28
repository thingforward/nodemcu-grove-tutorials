#include <Arduino.h>

void setup() {
	Serial.begin(9600);
	pinMode(D3, OUTPUT);
}

int value = LOW;

void loop() {
	value = !value;
	digitalWrite(D3, value);
	delay(1000);
}

