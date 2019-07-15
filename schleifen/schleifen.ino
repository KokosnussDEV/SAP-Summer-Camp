// Lass die Schleife 10 Mal, also von 0 bis 9, durchlaufen und gib
// in jedem Durchgang den aktuellen Wert der Schleifenvariable aus.

void setup() {
    Serial.begin(115200);
}

void loop() {
  int teiler;
  int zahl;
    for (zahl = 2; zahl <= 1000; zahl++) {
      bool prim = true;
        for (teiler = 2; prim && teiler <= (zahl + 1) / 2; teiler++) {

          if ((zahl % teiler) == 0) {
            prim = false;
          }
          delay(500);
          
        }
        if (prim) {
          Serial.println(String(zahl));
        }
    
    }

    delay(1000);
}
