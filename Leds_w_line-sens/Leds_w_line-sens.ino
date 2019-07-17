#include "Romi.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Romi robot;


void setup() {
  // put your setup code here, to run once:
  robot.init();
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(LINE_LEFT_PIN) == HIGH) {
    for (int i = 0; i < 6; i++) {
      robot.leds[i].setRGB(255, 255, 0);
    }
    robot.showLeds();
  } else if (digitalRead(LINE_LEFT_PIN) == LOW) {
    for (int i = 0; i < 6; i++){
      robot.leds[i].setRGB(255, 0, 0);
    }
    robot.showLeds();
  }
  lcd.setCursor(0, 0);
  lcd.print("SAP Summer");
  lcd.setCursor(0, 1);
  lcd.print("Viel Erfolg!");
}
