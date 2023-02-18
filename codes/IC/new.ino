#include <LiquidCrystal.h>
const int LEDR = 1;
const int LEDG = 2;
const int pin1 = 8;
const int pin2 = 9;
const int pin3 = 10;
const int pin4 = 11;
const int pin5 = 12;
const int pin6 = 13;
const int pin10 = A0;
const int pin9 = A1;
const int pin8 = A2;
const int pin13 = A3;
const int pin12 = A4;
const int pin11 = A5;
const int en=3,rs=2,D4=4,D5=5,D6=6,D7=7;
LiquidCrystal lcd(rs,en,D4,D5,D6,D7);

void setup() 
{
  lcd.begin(16,2);
  //gate 1
  pinMode(LEDR,OUTPUT); //Red led
  pinMode(LEDG,OUTPUT); //Green led
  pinMode(pin1,OUTPUT); //pin 1
  pinMode(pin2,OUTPUT); //pin 2
  pinMode(pin3,INPUT);  //pin 3 output of the 1st gate
  //gate 2
  pinMode(pin4,OUTPUT); //pin 4
  pinMode(pin5,OUTPUT); //pin 5
  pinMode(pin6,INPUT);  //pin 6 output of the 2nd gate
  //gate 3
  pinMode(pin10,OUTPUT); //pin 10
  pinMode(pin9,OUTPUT); //pin 9
  pinMode(pin8,INPUT);  //pin 8 output of 3rd the gate
  //gate 4
  pinMode(pin13,OUTPUT); //pin 13
  pinMode(pin12,OUTPUT); //pin 12
  pinMode(pin11,INPUT); //pin 11 output of the 4th
  
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  
  digitalWrite(pin4,HIGH);
  digitalWrite(pin5,LOW);
  
  digitalWrite(pin10,LOW);
  digitalWrite(pin9,HIGH);
  
  digitalWrite(pin13,HIGH);
  digitalWrite(pin12,HIGH);

  lcd.print("IC Tester");
  digitalWrite(LEDR,) 
  delay(500);
  lcd.clear();
  lcd.print("Testing IC");
  delay(100);
  lcd.print(".");
  delay(100);
  lcd.print(".");
  delay(100);
                                               
  delay(100);
  lcd.clear();
}

void loop()
{
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
}