#include <Arduino.h>
#include <Wire.h>
#include <TM1637Display.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

const char *ssid     = "<YOUR_SSID";
const char *password = "<YOUR_SSID_PASSWORD>";

TM1637Display display(D1, D2);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);

void setup(){
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    Serial.print ( "." );
    delay ( 500 );
  }

  Serial.println(WiFi.localIP());

  timeClient.begin();

  display.setBrightness(7);
}

bool secDots = false;

void loop(){
  secDots =! secDots;

  timeClient.update();

  int hours = timeClient.getHours();
  int minutes = timeClient.getMinutes();

  String minutesStr=minutes<10 ? ("0"+String(minutes)) : String(minutes);
  String timeStr = String(hours)+minutesStr;

  display.showNumberDecEx(timeStr.toInt(), secDots ? 255 : 1, true);

  delay(1000);
}
