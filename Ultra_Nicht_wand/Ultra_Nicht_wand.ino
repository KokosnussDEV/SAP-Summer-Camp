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
  robot.turn(0, 0);
  while (robot.distanceLeft() > 20 && robot.distanceFront() > 20 && robot.distanceRight() > 20) {
    robot.turn(0, 0);
    robot.driveStraight(300);
    robot.driveLoop();
  }
  robot.driveStraight(0);
  robot.turn(90, 500);
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
