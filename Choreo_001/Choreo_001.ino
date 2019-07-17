#include "Romi.h"

Romi robot;

void setup() {
  // put your setup code here, to run once:
  robot.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  while(robot.mesuredistance() < 25) {
    robot.turn(0, 0);
    robot.driveStraight(400);
    delay(4000);
    robot.driveStraight(0);
    delay(500);
    robot.driveStraight(500);
    delay(2000);
    robot.turn(185, 350);
  }
  robot.turn(185, 600);
  
}
