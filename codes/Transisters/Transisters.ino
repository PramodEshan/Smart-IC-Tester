#include <Arduino.h>

const int typePin = 2;       // HIGH = BJT, LOW = FET
const int basePin = 9;       // base/gate
const int collectorPin = 13; // collector/drain
const int emitterPin = 11;   // emitter/source

void setup() {
  pinMode(typePin, INPUT);
  pinMode(basePin, OUTPUT);
  pinMode(collectorPin, OUTPUT);
  pinMode(emitterPin, OUTPUT);
}

void loop() {
  int typeValue = digitalRead(typePin);
  if (typeValue == HIGH) {
    // BJT
    digitalWrite(basePin, LOW);
    digitalWrite(collectorPin, LOW);
    digitalWrite(emitterPin, LOW);
  } else {
    // FET
    digitalWrite(basePin, LOW);
    digitalWrite(collectorPin, LOW);
    digitalWrite(emitterPin, LOW);
  }
}
