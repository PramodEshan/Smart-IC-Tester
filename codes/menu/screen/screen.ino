#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <I2C_graphical_LCD_display.h>

LiquidCrystal_I2C lcd(0x27, 20,4);
const int selectButton = 16;

void setup() {
  lcd.init();
  lcd.begin(20,4);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("vdsdvsdv");
  pinMode(selectButton, OUTPUT);
  digitalWrite(selectButton, HIGH);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
