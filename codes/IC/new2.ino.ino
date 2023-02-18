#include <LiquidCrystal.h>

// Connect the data pins of the 74HC08N to digital pins 2 to 9
const int dataPin1 = 2;
const int dataPin2 = 3;
const int dataPin3 = 4;
const int dataPin4 = 5;
const int dataPin5 = 6;
const int dataPin6 = 7;
const int dataPin7 = 8;
const int dataPin8 = 9;

// Create an instance of the LiquidCrystal library
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);  //rs,e,D4,D5,D6,D7

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2);

  // Loop through all possible combinations of inputs
  for (int i = 0; i < 16; i++) {
    int input1 = (i & 1) ? HIGH : LOW;
    int input2 = (i & 2) ? HIGH : LOW;
    int input3 = (i & 4) ? HIGH : LOW;
    int input4 = (i & 8) ? HIGH : LOW;

    // Set the inputs
    digitalWrite(dataPin1, input1);
    digitalWrite(dataPin2, input2);
    digitalWrite(dataPin3, input3);
    digitalWrite(dataPin4, input4);

    // Read the state of the output
    int output = digitalRead(dataPin8);

    // Check if the state of the output matches the expected value for AND gate
    if (output != (input1 & input2 & input3 & input4)) {
      // If the output does not match the expected value, display "IC is NOT working" and the malfunctioning pins
      lcd.print("IC is NOT working");
      lcd.setCursor(0, 1);
      lcd.print("Malfunctioning Pins:");
      lcd.setCursor(0, 2);
      lcd.print("2 3 4 5");
      return;
    }
  }

  // If all tests passed, display "IC is working" and the name of the AND gate
  lcd.print("IC is working");
  lcd.setCursor(0, 1);
  lcd.print("AND Gate");
}

void loop() {
  // No need for loop code
}