# include "Romi.h"

Romi robot;


void setup() {
  robot.init();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  /* Serial.print(robot.readEncoderLeft());
  Serial.print(" ");
  Serial.println(robot.readEncoderRight());*/
  robot.turn(0, 0);
  robot.driveStraight(500);
  robot.driveLoop();
  delay(7000);
  robot.turn(200, 300);
}
