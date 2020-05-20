#include "Romi.h"

Romi robot;


void setup() {
  Serial.begin(115200);
  robot.init();
  robot.createTask(entfernungenAnzeigen, "entfernungenAnzeigen");
  
}

void loop() {
  robot.turn(0, 0);
  if (digitalRead(LINE_LEFT_PIN) == LOW) {
    robot.driveStraight(100);
    robot.driveLoop();
    delay(10);
  } else {
    robot.driveStraight(0);
    robot.driveLoop();
    while (true) {
      Serial.println(robot.distanceFront());
      if (robot.distanceFront() < 30 && robot.distanceFront() > 0) {
        robot.turn(0,0);
        if (digitalRead(LINE_LEFT_PIN) == HIGH) {
          robot.driveStraight(200);
          robot.driveLoop();
          delay(50);
          robot.driveStraight(0);
        } else if (digitalRead(LINE_LEFT_PIN) == LOW) {
          robot.turn(20, 200);
          robot.driveStraight(200);
          delay(1000);
          robot.driveStraight(0);
          if (digitalRead(LINE_LEFT_PIN) == LOW) {
            robot.turn(-45, 200);
            robot.driveStraight(200);
            delay(1000);
            robot.driveStraight(0);
          }
        }
      }else {
        robot.driveStraight(-50);
        robot.driveLoop();
        delay(100);
        robot.driveStraight(0);
        robot.driveLoop();
        robot.turn(360, 100);
      }
      
    }
  }
}

void entfernungenAnzeigen(void *pvParameters){
  while(true){
    int color = 2;
    for (int i = 0; i < 3; i++) {
      if ((color % 2) == 0) {
        robot.leds[i] = CRGB::Blue;
      }
      robot.leds[i] = CRGB::Red;
    }
    robot.showLeds();
    delay(100);
    for (int i = 0; i < 3; i++) {
      robot.leds[i] = CRGB::Black;
    }
    for (int i = 0; i < 3; i++) {
      if ((color % 2) == 0) {
        robot.leds[i+3] = CRGB::Red;
      }
      robot.leds[i+3] = CRGB::Blue;
    }
    robot.showLeds();
    delay(100);
    for (int i = 0; i < 3; i++) {
      robot.leds[i+3] = CRGB::Black;
    }
    robot.showLeds();
    color++;
   }
  }
