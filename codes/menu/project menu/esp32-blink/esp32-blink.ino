#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 4);

int upButton = 15;
int downButton = 2;
int selectButton = 4;
int backButton = 5;
int menu = 1;
int RED = 25;
int GREEN = 23;

void setup() {
  lcd.init();
  lcd.begin(16,4);
  lcd.backlight();
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(backButton, INPUT_PULLUP);
  updateMenu();
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH); 
}

void loop() {
  if (!digitalRead(downButton)){
    menu++;
    updateMenu();
    delay(100);
    while (!digitalRead(downButton));
  }
  if (!digitalRead(upButton)){
    menu--;
    updateMenu();
    delay(100);
    while(!digitalRead(upButton));
  }
  if (!digitalRead(selectButton)){
    //executeAction();
    updateMenu();
    delay(100);
    while (!digitalRead(selectButton));
  }
  if (!digitalRead(backButton)){
    menu = 5;
    //executeAction();
    updateMenu();
    delay(100);
    while (!digitalRead(backButton));
  }
}

void pinTest(){
  lcd.setCursor(0,0);
  lcd.print("Connection Test");
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  delay(1000);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  lcd.clear();
}

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("> 14 pin ICs");
      lcd.setCursor(16,0);
      lcd.print("Op-Amp 8pin");
      lcd.setCursor(8,0);
      lcd.print("Transistor");
      lcd.setCursor(24,0);
      lcd.print("Diode/Resisters");
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("> 14 pin ICs");
      lcd.setCursor(16,0);
      lcd.print("Op-Amp 8pin");
      lcd.setCursor(8,0);
      lcd.print("Transistor");
      lcd.setCursor(24,0);
      lcd.print("Diode/Resisters");
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("> 14 pin ICs");
      lcd.setCursor(16,0);
      lcd.print("Op-Amp 8pin");
      lcd.setCursor(8,0);
      lcd.print("Transistor");
      lcd.setCursor(24,0);
      lcd.print("Diode/Resisters");
      break;
    case 4:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("> 14 pin ICs");
      lcd.setCursor(16,0);
      lcd.print("Op-Amp 8pin");
      lcd.setCursor(8,0);
      lcd.print("Transistor");
      lcd.setCursor(24,0);
      lcd.print("Diode/Resisters");
      break;
    case 5:
      menu = 4;
      break;
  }
/*
void executeAction() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;
    case 5:
      action5();
      break;
  }
}

void action1() {
  lcd.clear();
  lcd.print(">Executing #1");
  delay(1500);
}
void action2() {
  lcd.clear();
  lcd.print(">Executing #2");
  delay(1500);
}
void action3() {
  lcd.clear();
  lcd.print(">Executing #3");
  delay(1500);
}
void action4() {
  lcd.clear();
  lcd.print(">Executing #4");
  delay(1500);
}
void action5() {
  lcd.clear();
  menu = 1;
}*/