//#--------------------------------------------------------------------------------------#
//| Thanks to Digikey for providing the kits and helping us make this an amazing Codeday!|
//#--------------------------------------------------------------------------------------#

#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R2, SCL, SDA, U8X8_PIN_NONE);  // High speed I2C

#define codeday_width 65
#define codeday_height 64
static const unsigned char codeday_bits[] PROGMEM = {
   0x00, 0x80, 0x7f, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x00, 0xf0, 0xff,
   0x03, 0x80, 0xff, 0x1f, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x0f, 0xe0, 0xff,
   0x7f, 0x00, 0x00, 0x00, 0xff, 0xff, 0x3f, 0xf8, 0xff, 0xff, 0x01, 0x00,
   0x80, 0xff, 0xff, 0x3f, 0xf8, 0xff, 0xff, 0x03, 0x00, 0xc0, 0xff, 0xff,
   0x3f, 0xf8, 0xff, 0xff, 0x07, 0x00, 0xe0, 0xff, 0xff, 0x3f, 0xf8, 0xff,
   0xff, 0x0f, 0x00, 0xf0, 0xff, 0xff, 0x3f, 0xf8, 0xff, 0xff, 0x1f, 0x00,
   0xf8, 0xff, 0xe1, 0x3f, 0xf8, 0x0f, 0xff, 0x3f, 0x00, 0xf8, 0x3f, 0x00,
   0x3f, 0xf8, 0x01, 0xf8, 0x3f, 0x00, 0xfc, 0x0f, 0x00, 0x3c, 0x78, 0x00,
   0xe0, 0x7f, 0x00, 0xfc, 0x07, 0x00, 0x38, 0x38, 0x00, 0xc0, 0x7f, 0x00,
   0xfe, 0x03, 0x00, 0x30, 0x18, 0x00, 0x80, 0xff, 0x00, 0xfe, 0x03, 0x00,
   0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0xfe, 0x01, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xff, 0x00, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01,
   0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0xff, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xfe, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01,
   0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0xff, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xff, 0x01, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01,
   0xfe, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xfe, 0x03, 0x00,
   0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0xfe, 0x03, 0x00, 0x00, 0x00, 0x00,
   0x80, 0xff, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x7f, 0x00,
   0xfc, 0x07, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x7f, 0x00, 0xfc, 0x03, 0x00,
   0x00, 0x00, 0x00, 0xc0, 0x7f, 0x00, 0xf8, 0x01, 0x00, 0x00, 0x00, 0x00,
   0x80, 0x3f, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00,
   0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x20, 0x40, 0x00,
   0x00, 0x00, 0x00, 0x02, 0x08, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00,
   0x07, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0x80, 0x0f, 0x00, 0x00,
   0x00, 0xf8, 0x07, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0xfc, 0x0f,
   0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0xfe, 0x1f, 0x00, 0x00, 0xf0,
   0x7f, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0xf8, 0x7f, 0x00, 0x00,
   0x00, 0xf8, 0x7f, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0x00, 0xf0, 0xff,
   0x00, 0x00, 0xfe, 0x1f, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x01, 0x00, 0xff,
   0x0f, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x03, 0x80, 0xff, 0x07, 0x00, 0x00,
   0x00, 0x80, 0xff, 0x07, 0xc0, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0xff,
   0x0f, 0xe0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x1f, 0xf0, 0x7f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0xf8, 0x3f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xf0, 0x7f, 0xfc, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0,
   0xff, 0xfe, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x07,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x7f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf8, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xf0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x0f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x0f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00 };

static
void setup(void) {

  u8g2.begin();

}

void draw(void) {
  u8g2.drawXBMP(0,0, codeday_width, codeday_height, codeday_bits); // Display the CodeDay logo at 0, 0
}
void loop(void) {

  u8g2.firstPage();
  do {
    draw();
  } while(u8g2.nextPage());
  
  delay(1000);
  }