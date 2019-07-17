#include "Romi.h"

Romi robot;


void setup() {
  // put your setup code here, to run once:
  robot.init();
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
}
