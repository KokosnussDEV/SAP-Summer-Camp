void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    char i = Serial.read();
    String i2 = String(i);
    Serial.print(i);
  }

}
