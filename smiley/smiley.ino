#include "Romi.h"
#include <LiquidCrystal_I2C.h>

Romi robot;
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000
};

void setup() {
  // put your setup code here, to run once:
  robot.init();
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.createChar(0, smiley);
  lcd.begin(16, 2);
  lcd.write(byte(0));
  delay(500);
}
