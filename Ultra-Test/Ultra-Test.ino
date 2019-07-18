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
  robot.measureDistances(entfernungen);
  for(int i = 0; i < 3; i++) {
    Serial.println(entfernungen[i]);
  }
  Serial.println("----------------------");
  delay(500);
}
