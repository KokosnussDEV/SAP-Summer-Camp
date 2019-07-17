# include "Romi.h"

Romi robot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  robot.init();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(robot.distanceLeft());
  Serial.print(" ");
  Serial.print(robot.distanceFront());
  Serial.print(" ");
  Serial.println(robot.distanceRight());
}
