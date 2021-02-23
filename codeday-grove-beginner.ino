//#--------------------------------------------------------------------------------------#
//| Thanks to Digikey for providing the kits and helping us make this an amazing Codeday!|
//#--------------------------------------------------------------------------------------#

#include <U8g2lib.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include "DS1307.h"

//Enables features.
#define mech_key = true;
//#define rtc = true;
char kit = "beginner"; //unused rn

//Board pin numbers and other variables
char led = 4;
char buzzer = 5;
int owo = 0;
int fadeSpeed = 5;
int fadeInterval = 1;

//Some premade colors UwU (in RGB)
int purple[3] = {255,0,255};
int yellow[3] = {255,255,0};
int teal[3] = {0,255,255};
int red[3] = {255,0,0};
int green[3] = {0,255,0};
int blue[3] = {0,0,255};
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R2, /* reset=*/U8X8_PIN_NONE);

//A tiny bit of logic to enable certain modules
#ifdef rtc
DS1307 clock;
#endif
#ifdef mech_key
char button = 2;
char pixel_pin = 3;
Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, pixel_pin, NEO_GRB + NEO_KHZ800);
#endif
#ifndef mech_key
char button = 6;
#endif

void setup() {
  #ifdef rtc
  Serial.begin(9600);
  clock.begin();
  clock.fillByYMD(1970,1,1);
  clock.fillByHMS(0,0,0);
  clock.fillDayOfWeek(THU);
  #endif
  #ifdef mech_key
  pinMode(button, INPUT);
  pixel.begin();
  pixel.clear();
  pixel.setPixelColor(0,pixel.Color(255,0,255));
  pixel.show();
  #endif
}

void loop() {
  //fade in and out mech key led
  #ifdef mech_key
  if(digitalRead(button) == true) {
    pixel.setPixelColor(0,pixel.Color(purple[0],purple[1],purple[2]));
    pixel.show();
  } else {
    while(digitalRead(button) == false) {
      owo = owo+fadeInterval;
      pixel.setPixelColor(0,pixel.Color(owo,owo,owo));
      pixel.show();
      if (owo <=0 || owo>=255) {
        fadeInterval = -fadeInterval;
      }
      delay(fadeSpeed);
    }
  }
  #endif
}
