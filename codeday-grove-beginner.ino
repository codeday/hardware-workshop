//#--------------------------------------------------------------------------------------#
//| Thanks to Digikey for providing the kits and helping us make this an amazing Codeday!|
//#--------------------------------------------------------------------------------------#

#include <U8g2lib.h> //Library for the screen
#include <Wire.h> //For I2C (How the display and board talk to each other)
#include <Adafruit_NeoPixel.h> //Mech key, remove in final revisions
#include <Arduino.h> //required for screen, idk what rn

//Enables addon modules.
#define mech_key

//Board pin numbers and other variables
char led = 4;
char buzzer = 5;
bool hatched = false; //to store if the egg has hatched
int millis_since_press = 0;
char button = 2;


U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE); 

void drawSmallEgg(){
  u8g2.clearBuffer(); //Clears the screen
  u8g2.drawCircle(63,31,20); //sad excuse for an egg but works
  u8g2.drawLine(0,0,0,63); //Makes a square around the screen
  u8g2.drawLine(0,0,127,0);
  u8g2.drawLine(127,0,127,63);
  u8g2.drawLine(0,63,127,63);
  u8g2.sendBuffer(); //Sends image to the screen
  delay(750);
}
void drawBigEgg() {
  u8g2.clearBuffer(); //Clears the screen
  u8g2.drawCircle(63,31,15); //sad excuse for an egg but works
  u8g2.drawLine(0,0,0,63); //Makes a square around the screen
  u8g2.drawLine(0,0,127,0);
  u8g2.drawLine(127,0,127,63);
  u8g2.drawLine(0,63,127,63);
  u8g2.sendBuffer(); //Sends image to screen
  delay(750);
}

void setup() {
  u8g2.begin(); //Tells the screen to start
  u8g2.clearBuffer(); //Clears the screen
  u8g2.setFont(u8g2_font_ncenB08_tr); //Sets the font the screen uses
  while (digitalRead(button) == LOW) {
    u8g2.clearBuffer(); //Clears the screen
    u8g2.drawStr(30,20,"JojiGotchi"); //Title screen
    u8g2.drawStr(25,45,"Press Any Button");
    u8g2.sendBuffer();
  }
  millis_since_press = millis();
  while (millis() - millis_since_press <= 300000) { //checks if hatching time is less than 5 mins
    drawSmallEgg();
    drawBigEgg();
  }
  u8g2.clearBuffer();
  u8g2.drawStr(10,41,"HATCHED UWU");
  u8g2.sendBuffer();
}

void loop() {
  
}
