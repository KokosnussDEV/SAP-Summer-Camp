#include "Romi.h"

Romi robot;


void setup() {
  // put your setup code here, to run once:
  robot.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  robot.turn(0,0);
  if (digitalRead(LINE_LEFT_PIN) == HIGH) {
    for (int i = 0; i < 6; i++) {
      robot.leds[i].setRGB(255, 255, 0);
    }
    robot.showLeds();
    robot.driveStraight(300);
    robot.driveLoop();
    delay(50);
    robot.driveStraight(0);
  } else if (digitalRead(LINE_LEFT_PIN) == LOW) {
    for (int i = 0; i < 6; i++){
      robot.leds[i].setRGB(255, 0, 0);
    }
    robot.showLeds();
    robot.turn(20, 200);
    robot.driveStraight(300);
    delay(1000);
    robot.driveStraight(0);
    if (digitalRead(LINE_LEFT_PIN) == LOW) {
       robot.turn(-45, 200);
       robot.driveStraight(300);
       delay(1000);
       robot.driveStraight(0);
    }
  }
}
