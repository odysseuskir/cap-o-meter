/*
 * Authors: Odysseus-Abraham Kirikopoulos & Nikos Tsilas
 * This program is under the GNU General Public License V3
 */

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Recognizing LCD

int sensorPin = 13; // Output pin

int alarmPin = 8; // Buzzer
int ledPin = 9; // LED

int count = 0; // How mamy cups have been collected
float percentage;
String percentage_str;

void setup() {

  lcd.init(); // Initialize the lcd
  lcd.backlight(); // Turn on the backlight

  pinMode(sensorPin, INPUT); // Sets the sensorPin as an Output

  pinMode(alarmPin, OUTPUT); // Sets the alarmPin as an Output
  
  Serial.begin(9600); // Starts the serial communication

}

void loop() {

  lcd.setCursor(0,1); // Set the cursor to the first column, second row
  lcd.print("Target = 540.000"); // Print the target
  lcd.setCursor(0,0); // Set the cursor to the first column, first row
  lcd.print("Cups:"); // Print the cups

  int reading = digitalRead(sensorPin);

  if (reading == 1) { // If the reading is true
   
      count++; // Increase the count by 1

      digitalWrite(alarmPin, HIGH); // Turn on the alarm
      digitalWrite(ledPin, HIGH); // Turn on the LED

      calculatePercentage();
      Serial.println(count); // Print the count on the serial monitor
     
      delay(10); // Waits 50 milliseconds
     
  } else {

     digitalWrite(alarmPin, LOW); // Turn off the alarm
     digitalWrite(ledPin, LOW); // Turn off the LED
    
  }

  lcd.setCursor(5,0); // Set the cursor to the fifth column, first row
  lcd.print(count); // Print the count
  lcd.setCursor(11, 0);
  lcd.print(percentage_str);
  
  delay(10);  // Waits 50 milliseconds

}

void calculatePercentage() {

  percentage = count / 5400;

  percentage = ((int)percentage) + 1;

  percentage_str = String(percentage) + "%";

}