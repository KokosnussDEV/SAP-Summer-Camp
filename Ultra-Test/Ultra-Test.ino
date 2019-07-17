# include "Romi.h"

Romi robot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  robot.init();

}

void loop() {
  // put your main code here, to run repeatedly:
  double entfernungen[3];
  Serial.print(robot.distanceLeft());
  Serial.print(" ");
  Serial.print(robot.distanceFront());
  Serial.print(" ");
  Serial.println(robot.distanceRight());
  robot.measureDistances(entfernungen);
  Serial.print(entfernungen[1]);
  Serial.println(" ");
}
