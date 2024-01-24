#include <U8g2lib.h>
#include <Wire.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
const char COPYRIGHT_SYMBOL[] = { 0xa9, '\0' };

void u8g2_prepare() {
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);
}
//https://github.com/olikraus/u8g2/wiki/u8g2reference
void u8g2_box_frame() {
  u8g2.drawStr(0, 0, "drawBox");
  u8g2.drawBox(5, 10, 20, 10);
  u8g2.drawStr(60, 0, "drawFrame");
  u8g2.drawFrame(65, 10, 20, 10);
}

void DrawCustom() {
  u8g2.setFontMode(1);  /* activate transparent font mode */
  u8g2.setDrawColor(1); /* color 1 for the box */
  u8g2.drawBox(22, 2, 35, 50);
  u8g2.setFont(u8g2_font_ncenB14_tf);
  u8g2.setDrawColor(0);
  u8g2.drawStr(5, 18, "abcd");
  u8g2.setDrawColor(1);
  u8g2.drawStr(5, 33, "abcd");
  u8g2.setDrawColor(2);
  u8g2.drawStr(5, 48, "abcd");
}

void setup(void) {
  u8g2.begin();
  u8g2_prepare();
}
void loop(void) {
  u8g2.clearBuffer();
  u8g2_prepare();
  u8g2_box_frame();
  u8g2.sendBuffer();
  delay(1500);
  u8g2.clearBuffer();
  DrawCustom();
  u8g2.sendBuffer();
  delay(1500);
}
