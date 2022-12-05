/*
Author: Odysseus-Abraham Kirikopoulos
This program is protected under the GNU General Public License v3.0
*/

#include <SevSeg.h>

// Declare variables

int echoPin = A1; // Echo Pin
int trigPin = 13; // Trigger Pin

long duration; // Duration used to calculate distance
long distance; // Distance in cm

int pinA = 11; // Pins for 7-Segment Display
int pinB = 7;
int pinC = 4;
int pinD = 2;
int pinE = 1;
int pinF = 10;
int pinG = 5;
int pinDP = 3;
int D1 = 12;
int D2 = 9;
int D3 = 8;
int D4 = 6;

// Counter

int count_1000 = 0; // Example: In num 1234 this represents 1000
int count_100 = 0; // Example: In num 1234 this represents 200
int count_10 = 0; // Example: In num 1234 this represents 30
int count_1 = 0; // Example: In num 1234 this represents 4
int count = count_1000 + count_100 + count_10 + count_1;

void setup() {

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  pinMode(pinA, OUTPUT); // Sets all display segments & digits as outputs
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  digit1();zero(); // Sets display to 0000
  digit2();zero();
  digit3();zero();
  digit4();zero();

}

void loop() {

  digitalWrite(trigPin, LOW); // Sets the trigPin on LOW state for 2 micro seconds
  delayMicroseconds(2); // 2 microsecond pause to ensure a clean LOW pulse
  digitalWrite(trigPin, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10); // 0 microsecond pause to ensure a clean HIGH pulse
  digitalWrite(trigPin, LOW); // Sets the trigPin on LOW state

  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration/58.2; // Calculating the distance

  if (distance > 4) {
    
      if (count_1 > 9) {
        count_1 = 0;
        if (count_10 > 9) {
          count_10 = 0;
          if (count_100 > 9) {
            count_100 = 0;
            if (count_1000 > 9) {
              count_1000 = 0;
              digit1();zero();
              digit2();zero();
              digit3();zero();
              digit4();zero();
            } else {
              count_1000++;
            }
          } else {
            count_100++;
          }
        } else {
          count_10++;
        }
      } else {
        count_1++;
      }
      
      delay(50); // Waits 50 milliseconds
  }

  turnOnAllDigits();
  updateAllDigits();

  count = count_1000 + count_100 + count_10 + count_1;
  
  Serial.println(count);

  delay(5);  // Waits 5 milliseconds

}

// Update digits

void updateDigit1() {

   if (count_1000 = 0) {
    digit1();zero();
   } else if (count_1000 = 1) {
    digit1();one();
   } else if (count_1000 = 2) {
    digit1;two();
   } else if (count_1000 = 3) {
    digit1;three();
   } else if (count_1000 = 4) {
    digit1;four();
   } else if (count_1000 = 5) {
    digit1;five();
   } else if (count_1000 = 6) {
    digit1;six();
   } else if (count_1000 = 7) {
    digit1;seven();
   } else if (count_1000 = 8) {
    digit1;eight();
   } else if (count_1000 = 9) {
    digit1;nine();
   }

}

void updateDigit2() {

   if (count_100 = 0) {
    digit2();zero();
   } else if (count_100 = 1) {
    digit2();one();
   } else if (count_100 = 2) {
    digit2;two();
   } else if (count_100 = 3) {
    digit2;three();
   } else if (count_100 = 4) {
    digit2;four();
   } else if (count_100 = 5) {
    digit2;five();
   } else if (count_100 = 6) {
    digit2;six();
   } else if (count_100 = 7) {
    digit2;seven();
   } else if (count_100 = 8) {
    digit2;eight();
   } else if (count_100 = 9) {
    digit2;nine();
   }

}

void updateDigit3() {

   if (count_10 = 0) {
    digit3();zero();
   } else if (count_10 = 1) {
    digit3();one();
   } else if (count_10 = 2) {
    digit3;two();
   } else if (count_10 = 3) {
    digit3;three();
   } else if (count_10 = 4) {
    digit3;four();
   } else if (count_10 = 5) {
    digit3;five();
   } else if (count_10 = 6) {
    digit3;six();
   } else if (count_10 = 7) {
    digit3;seven();
   } else if (count_10 = 8) {
    digit3;eight();
   } else if (count_10 = 9) {
    digit3;nine();
   }

}

void updateDigit4() {

   if (count_1 = 0) {
    digit4();zero();
   } else if (count_1 = 1) {
    digit4();one();
   } else if (count_1 = 2) {
    digit4;two();
   } else if (count_1 = 3) {
    digit4;three();
   } else if (count_1 = 4) {
    digit4;four();
   } else if (count_1 = 5) {
    digit4;five();
   } else if (count_1 = 6) {
    digit4;six();
   } else if (count_1 = 7) {
    digit4;seven();
   } else if (count_1 = 8) {
    digit4;eight();
   } else if (count_1 = 9) {
    digit4;nine();
   }

}

void updateAllDigits() {

  updateDigit1();
  updateDigit2();
  updateDigit3();
  updateDigit4();
  
}

// Numbers from 0-9

void zero(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void one(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void two(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}
  
void three(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}
    
void four(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
    
void five(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
    
void six(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
    
void seven(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
    
void eight(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
    
void nine(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void allNumbers(){
  one();delay(500);
  two();delay(500);
  three();delay(500);
  four();delay(500);
  five();delay(500);
  six();delay(500);
  seven();delay(500);
  eight();delay(500);
  nine();delay(500);
}


// Individual digits

void digit1(){
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}
      
void digit2(){
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}
      
void digit3(){
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
}
      
void digit4(){
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
}

void turnOnAllDigits(){
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}

void turnOffAllSegments(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

// ODYSSEUS-ABRAHAM KIRIKOPOULOS | 2022 | GNU GENERAL PUBLIC LICENSE V3.0 | SOME RIGHTS RESERVED