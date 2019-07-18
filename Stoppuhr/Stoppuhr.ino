#include "Romi.h"
#include <LiquidCrystal_I2C.h>

Romi robot;
LiquidCrystal_I2C lcd(0x27, 16, 2);



void setup() {
  // put your setup code here, to run once:
  robot.init();
  lcd.init();
  lcd.backlight();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  long zeit = millis();
  lcd.begin(16, 2);
  lcd.setCursor(1, 1);
  
  if (digitalRead(BUTTON_PIN) == LOW) {
    long zeitVergangen = 0;
    while(digitalRead(BUTTON_PIN) == HIGH) {
        zeitVergangen++;
        //lcd.print(String(zeitVergangen));
        Serial.println(zeitVergangen);
        delay(1000);
    }
  }
}
