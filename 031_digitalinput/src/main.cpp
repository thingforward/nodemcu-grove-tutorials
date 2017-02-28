#include <Arduino.h>

void setup() {
	Serial.begin(9600);
	pinMode(D3, INPUT);
}

void loop() {
	int v = digitalRead(D3);
	Serial.println(v);
	delay(1000);
}

