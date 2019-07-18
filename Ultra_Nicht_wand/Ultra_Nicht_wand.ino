#include "Romi.h"

Romi robot;


void setup() {
  // put your setup code here, to run once:
  robot.init();
  Serial.begin(115200);
  robot.createTask(entfernungenAnzeigen, "entfernungenAnzeigen");
 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (robot.distanceLeft() < 30 && robot.distanceFront() < 30 && robot.distanceRight() < 30) {
      for (int i = 300; i >= 0; i = i - 50) {
        robot.turn(0, 0);
        robot.driveStraight(i);
        robot.driveLoop();
        delay(50);
      }
      robot.turn(5, 300);
  } else {
      robot.turn(0, 0);
      for (int i = 0; i <= 300; i = i + 50) {
        robot.turn(0, 0);
        robot.driveStraight(i);
        robot.driveLoop();
        delay(50);
      }
   }
  
}

void entfernungenAnzeigen(void *pvParameters){
  while(true){
    int left = robot.distanceLeft();
    int front = robot.distanceFront();
    int right = robot.distanceRight();
    
    Serial.println("Werte gemessen");
    robot.leds[0].setHSV(255, 255, left);
    robot.leds[1].setHSV(255, 255, left);
    robot.leds[2].setHSV(160, 255, front);
    robot.leds[3].setHSV(160, 255, front);
    robot.leds[4].setHSV(55, 255, right);
    robot.leds[5].setHSV(55, 255, right);
    robot.showLeds();
   }
  }
