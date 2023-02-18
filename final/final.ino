#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

const int pin14 = A0;
const int pin13 = A1;
const int pin12 = A2;
const int pin11 = A3;
const int pin10 = A4;
const int pin9 = A5;
const int pin8 = A6;
const int piny = A7;
const int pin1 = A8;
const int pin2 = A9;
const int pin3 = A10;
const int pin4 = A11;
const int pin5 = A12;
const int pin6 = A13;
const int pin7 = A14;
const int pinx = A15;

const int RED = 25;
const int GREEN = 23;
const int downButton = 19;
const int upButton = 18;
const int selectButton = 17;
const int backButton = 16;

int menu = 1;


void setup() {
  lcd.init();
  lcd.begin(20,4);
  lcd.backlight();
  lcd.clear();

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(backButton, INPUT_PULLUP);

  pinTest();
  updateMenu();
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
    executeAction();
    updateMenu();
    delay(100);
    while (!digitalRead(selectButton));
  }
  if (!digitalRead(backButton)){
    menu = 5;
    executeAction();
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
      lcd.print("> 2 input Gate");
      lcd.setCursor(16,0);
      lcd.print("3 input Gate");
      lcd.setCursor(8,0);
      lcd.print("4 input Gate");
      lcd.setCursor(24,0);
      lcd.print("Op-Amp 8 pin");
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("2 input Gate");
      lcd.setCursor(16,0);
      lcd.print("> 3 input Gate");
      lcd.setCursor(8,0);
      lcd.print("4 input Gate");
      lcd.setCursor(24,0);
      lcd.print("Op-Amp 8 pin");
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("2 input Gate");
      lcd.setCursor(16,0);
      lcd.print("3 input Gate");
      lcd.setCursor(8,0);
      lcd.print("> 4 input Gate");
      lcd.setCursor(24,0);
      lcd.print("Op-Amp 8 pin");
      break;
    case 4:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("2 input Gate");
      lcd.setCursor(16,0);
      lcd.print("3 input Gate");
      lcd.setCursor(8,0);
      lcd.print("4 input Gate");
      lcd.setCursor(24,0);
      lcd.print("> Op-Amp 8 pin");
      break;
    case 5:
      menu = 4;
      break;
 }
}

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
  int i;
  int pins[] = {pin1,pin2,pin3,pin4,pin5,pin6,pin7,pin8,pin9,pin10,pin11,pin12,pin13,pin14};
  int outputpins[] = {pin1,pin2,pin4,pin5,pin7,pin9,pin10,pin12,pin13,pin14};
  int inputpins[] = {pin3,pin6,pin8,pin11};
  for(i=0;i<10;i++){
    pinMode(outputpins[i],OUTPUT);
  }
  for(i=0;i<4;i++){
    pinMode(inputpins[i],INPUT);
  }
  
  digitalWrite(pin7,LOW);
  digitalWrite(pin14,HIGH);
  
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  
  digitalWrite(pin4,HIGH);
  digitalWrite(pin5,LOW);
  
  digitalWrite(pin10,LOW);
  digitalWrite(pin9,HIGH);
  
  digitalWrite(pin13,HIGH);
  digitalWrite(pin12,HIGH);

  lcd.print("IC Tester"); 
  delay(1000);
  lcd.clear();
  lcd.print("Testing IC");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.clear();

  if(digitalRead(pin3)==HIGH)
  {
    if(digitalRead(pin6)==HIGH){
      lcd.print("NAND GATE");
      delay(10000);
    }
    else{
      if(digitalRead(pin8)==HIGH){
      	lcd.print("XNOR GATE");
      	delay(10000);
      }
      else{
        lcd.print("XNOR GATE");
      	delay(10000);
      }
    }
  }
  else{
    if(digitalRead(pin6)==LOW){
      lcd.print("AND GATE");
      delay(10000);
    }
    else{
      if(digitalRead(pin8)==HIGH){
        lcd.print("XOR GATE");
      	delay(10000);
      }
      else{
        lcd.print("OR GATE");
      	delay(10000);
      }
    }
  }
  for(i=0;i<14;i++){
    digitalWrite(pins[i],LOW);
  }
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
}