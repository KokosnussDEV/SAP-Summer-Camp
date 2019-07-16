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
  Serial.println(robot.readEncoderRight());
  delay(1000); */
  robot.turn(270, 500);
  robot.driveStraight(500);
  robot.driveLoop();
  delay(1000);
}
