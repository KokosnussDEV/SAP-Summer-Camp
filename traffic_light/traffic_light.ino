// Baut eine Bedarfsampel für Autofahrer und Fußgänger.

#include "Romi.h"

Romi robot;

void setup() {
    robot.init();
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
    // Bedarfsampel
    if (digitalRead(BUTTON_PIN) == LOW) {
      ampelSchaltung();
    } else {
      resetLEDS();
    }
}

void ampelSchaltung() {
    delay(100);

    robot.leds[5].setRGB(0, 0, 0);
    delay(100);
    robot.leds[4].setRGB(255, 255, 0);
    delay(100);
    for (int i = 3; i > 0; i--) {
      robot.leds[2].setRGB(255, 255, 0);
      robot.showLeds();
      delay(500);
      robot.leds[2].setRGB(0, 0, 0);
      robot.showLeds();
      delay(500);
    }
    robot.leds[4].setRGB(0, 0, 0);
    robot.leds[3].setRGB(255, 0, 0);
    robot.showLeds();
    delay(500);
    robot.leds[1].setRGB(0, 255, 0);
    robot.leds[0].setRGB(0, 0, 0);
    robot.showLeds();
    delay(20000);
    robot.leds[0].setRGB(255, 0, 0);
    robot.leds[1].setRGB(0, 0, 0);
    robot.showLeds();
    delay(500);
    robot.leds[3].setRGB(0, 0, 0);
    robot.leds[4].setRGB(255, 255, 0);
    robot.showLeds();
    delay(750);
    robot.leds[5].setRGB(0, 255, 0);
    robot.leds[4].setRGB(0, 0, 0);
    robot.showLeds();
}

void resetLEDS() {
    robot.leds[0].setRGB(255, 0, 0);
    robot.leds[1].setRGB(0, 0, 0);
    robot.leds[2].setRGB(0, 0, 0);
    robot.leds[3].setRGB(0, 0, 0);
    robot.leds[4].setRGB(0, 0, 0);
    robot.leds[5].setRGB(0, 255, 0);
    
    robot.showLeds();
}
