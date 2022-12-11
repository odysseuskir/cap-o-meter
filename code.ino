/*
 * Authors: Odysseus-Abraham Kirikopoulos & Nikos Tsilas
 * This program is under the GNU General Public License V3
 */

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Recognizing LCD

int echoPin = A1; // Echo Pin
int trigPin = A2; // Trigger Pin

int alarmPin = 8; // Buzzer
int ledPin = 9; // LED

int count = 0; // How mamy cups have been collected
long duration; // Duration used to calculate distance
long distance; // Distance in cm

void setup() {

  lcd.init(); // Initialize the lcd
  lcd.backlight(); // Turn on the backlight

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  pinMode(alarmPin, OUTPUT); // Sets the alarmPin as an Output
  
  Serial.begin(9600); // Starts the serial communication

}

void loop() {

  lcd.setCursor(0,1); // Set the cursor to the first column, second row
  lcd.print("Target = 540.000"); // Print the target
  lcd.setCursor(0,0); // Set the cursor to the first column, first row
  lcd.print("Cups:"); // Print the cups
  digitalWrite(trigPin, LOW); // Sets the trigPin on LOW state
  delayMicroseconds(2); // Delay of 2 microseconds
  digitalWrite(trigPin, HIGH); // Sets the trigPin on HIGH state
  delayMicroseconds(10); // Delay of 10 microseconds
  digitalWrite(trigPin, LOW); // Sets the trigPin on LOW state

  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration/58.2; // Calculating the distance

  if (distance > 4) { // If the distance is bigger than 4 cm
   
      count++; // Increase the count by 1

      digitalWrite(alarmPin, HIGH); // Turn on the alarm
      digitalWrite(ledPin, HIGH); // Turn on the LED

      Serial.println(count); // Print the count on the serial monitor
     
      delay(50); // Waits 50 milliseconds
     
  } else {

     digitalWrite(alarmPin, LOW); // Turn off the alarm
     digitalWrite(ledPin, LOW); // Turn off the LED
    
  }

  lcd.setCursor(5,0); // Set the cursor to the fifth column, first row
  lcd.print(count); // Print the count
  
  delay(50);  // Waits 50 milliseconds
  
  lcd.clear(); // Clear the lcd
  

}
