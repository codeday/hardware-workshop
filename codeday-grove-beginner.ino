//#--------------------------------------------------------------------------------------#
//| Thanks to Digikey for providing the kits and helping us make this an amazing Codeday!|
//#--------------------------------------------------------------------------------------#

#include <U8g2lib.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include "DS1307.h"

//Enables features.
#define mech_key
char kit = "beginner"; //unused rn

//Board pin numbers and other variables
char led = 4;
char buzzer = 5;
int color = 0;
int fadeSpeed = 5;
int fadeInterval = 1;


U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE); 

//A tiny bit of logic to enable certain modules
#ifdef mech_key
char button = 2;
char pixel_pin = 3;
Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, pixel_pin, NEO_GRB + NEO_KHZ800);
#endif
#ifndef mech_key
char button = 6;
#endif

void setup() {
  u8g2.begin();
  #ifdef mech_key
  pinMode(button, INPUT);
  pixel.begin();
  pixel.clear();
  pixel.setPixelColor(0,pixel.Color(255,0,255));
  pixel.show();
  #endif
  u8g2.clearBuffer(); 
  u8g2.setFont(u8g2_font_ncenB08_tr);
}

void loop() {
  //fade in and out mech key led
  #ifdef mech_key
  if(digitalRead(button) == true) {
    pixel.setPixelColor(0,pixel.Color(255,0,255));
    pixel.show();
    u8g2.clearBuffer();
    u8g2.drawStr(10,50,"PORPL");
    u8g2.sendBuffer();
  } else {
    while(digitalRead(button) == false) {
      color = color+fadeInterval;
      pixel.setPixelColor(0,pixel.Color(color,color,color));
      pixel.show();
      u8g2.clearBuffer();
      u8g2.drawStr(10,50,"Hello World color");
      u8g2.sendBuffer();
      if (color <=0 || color>=255) {
        fadeInterval = -fadeInterval;
      }
      delay(fadeSpeed);
    }
  }
  #endif
}
