/*
Author: Odysseus-Abraham Kirikopoulos
This program is protected under the GNU General Public License v3.0
*/

int echoPin = 12; // Echo Pin
int trigPin = 13; // Trigger Pin
int maximumRange = 30; // Maximum range needed
long duration, distance; // Duration used to calculate distance | Distance in cm
int pinA = 11;int pinB = 7;int pinC = 4;int pinD = 2;
int pinE = 1;int pinF = 10;int pinG = 5;
int pinDP = 3;int D1 = A1;int D2 = 9;int D3 = 8; int D4 = 6;
int count[] = {0, 0, 0, 0};

void setup() {

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  pinMode(pinA, OUTPUT);
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

  digit1();zero();
  digit2();zero();
  digit3();zero();
  digit4();zero();

}

void loop() {

  analogWrite(trigPin, LOW); // Sets the trigPin on LOW state for 2 micro seconds
  delayMicroseconds(2); // 2 microsecond pause to ensure a clean LOW pulse
  analogWrite(trigPin, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10); // 0 microsecond pause to ensure a clean HIGH pulse
  analogWrite(trigPin, LOW); // Sets the trigPin on LOW state

  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration/58.2; // Calculating the distance

  if (distance > 4) {
    
      if (count[3] > 9) {
        count[3] = 0;
        if (count[2] > 9) {
          count[2] = 0;
          if (count[1] > 9) {
            count[1] = 0;
            if (count[0] > 9) {
              count[0] = 0;
              digit1();zero();
              digit2();zero();
              digit3();zero();
              digit4();zero();
            } else {
              count[0]++;
            }
          } else {
            count[1]++;
          }
        } else {
          count[2]++;
        }
      } else {
        count[3]++;
      }
      
      delay(50); // Waits 50 milliseconds
  }

  updateAllDigits();
  
//  Serial.println(count[0]);
//  Serial.println(count[1]);
//  Serial.println(count[2]);
//  Serial.println(count[3]);

  Serial.println(distance);

  delay(5);  // Waits 5 milliseconds

}

// Update digit functions

void updateDigit1() {

   if (count[0] = 0) {
    digit1();zero();
   } else if (count[0] = 1) {
    digit1();one();
   } else if (count[0] = 2) {
    digit1;two();
   } else if (count[0] = 3) {
    digit1;three();
   } else if (count[0] = 4) {
    digit1;four();
   } else if (count[0] = 5) {
    digit1;five();
   } else if (count[0] = 6) {
    digit1;six();
   } else if (count[0] = 7) {
    digit1;seven();
   } else if (count[0] = 8) {
    digit1;eight();
   } else if (count[0] = 9) {
    digit1;nine();
   }

}

void updateDigit2() {

   if (count[1] = 0) {
    digit2();zero();
   } else if (count[1] = 1) {
    digit2();one();
   } else if (count[1] = 2) {
    digit2;two();
   } else if (count[1] = 3) {
    digit2;three();
   } else if (count[1] = 4) {
    digit2;four();
   } else if (count[1] = 5) {
    digit2;five();
   } else if (count[1] = 6) {
    digit2;six();
   } else if (count[1] = 7) {
    digit2;seven();
   } else if (count[1] = 8) {
    digit2;eight();
   } else if (count[1] = 9) {
    digit2;nine();
   }

}

void updateDigit3() {

   if (count[2] = 0) {
    digit3();zero();
   } else if (count[2] = 1) {
    digit3();one();
   } else if (count[2] = 2) {
    digit3;two();
   } else if (count[2] = 3) {
    digit3;three();
   } else if (count[2] = 4) {
    digit3;four();
   } else if (count[2] = 5) {
    digit3;five();
   } else if (count[2] = 6) {
    digit3;six();
   } else if (count[2] = 7) {
    digit3;seven();
   } else if (count[2] = 8) {
    digit3;eight();
   } else if (count[2] = 9) {
    digit3;nine();
   }

}

void updateDigit4() {

   if (count[3] = 0) {
    digit4();zero();
   } else if (count[3] = 1) {
    digit4();one();
   } else if (count[3] = 2) {
    digit4;two();
   } else if (count[3] = 3) {
    digit4;three();
   } else if (count[3] = 4) {
    digit4;four();
   } else if (count[3] = 5) {
    digit4;five();
   } else if (count[3] = 6) {
    digit4;six();
   } else if (count[3] = 7) {
    digit4;seven();
   } else if (count[3] = 8) {
    digit4;eight();
   } else if (count[3] = 9) {
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

// Activation of individual digits

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

// ODYSSEUS-ABRAHAM KIRIKOPOULOS | 2022 | GNU GENERAL PUBLIC LICENSE V3.0 | SOME RIGHTS RESERVED
