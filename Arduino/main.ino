/*
 * Authors: Odysseus-Abraham Kirikopoulos & Nikos Tsilas
 * This program is under the GNU General Public License V3
 */

#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Recognizing LCD

int sensorPin = 13; // Output pin

int alarmPin = 8; // Buzzer
int ledPin = 9; // LED
int switchPin = 6; // Switch

int count = 0; // How mamy cups have been collected

void setup() {

  lcd.init(); // Initialize the lcd
  lcd.backlight(); // Turn on the backlight

  pinMode(sensorPin, INPUT); // Sets the sensorPin as an Output
  pinMode(alarmPin, OUTPUT); // Sets the alarmPin as an Output
  pinMode(switchPin, INPUT_PULLUP);
  
  Serial.begin(9600); // Starts the serial communication

  if (EEPROM.read(0) == 0) {

    EEPROM.write(0, count);
   
  } else if (EEPROM.read(0) >= 540000) {

    count = 0;
    EEPROM.write(0, 0);
  
  } else {

    count = EEPROM.read(0);
    
  }

}

void loop() {

  lcd.setCursor(0,1); // Set the cursor to the first column, second row
  lcd.print("Target = 540.000"); // Print the target
  lcd.setCursor(0,0); // Set the cursor to the first column, first row
  lcd.print("Cups:"); // Print the cups

  int sensorState = digitalRead(sensorPin);
  int switchState = digitalRead(switchPin);

  if (sensorState == 1) { // If the sensorState is true
   
      count++; // Increase the count by 1

      digitalWrite(alarmPin, HIGH); // Turn on the alarm
      digitalWrite(ledPin, HIGH); // Turn on the LED
     
      delay(10); // Waits 50 milliseconds
     
  } else {

     digitalWrite(alarmPin, LOW); // Turn off the alarm
     digitalWrite(ledPin, LOW); // Turn off the LED
    
  }

  if (switchState == LOW) {

    count = 0;
    EEPROM.update(0, 0);

  }

  lcd.setCursor(5,0); // Set the cursor to the fifth column, first row
  lcd.print(count); // Print the count

  Serial.println(count); // Print the count on the serial monitor

  EEPROM.update(0, count);
  
  delay(10);  // Waits 50 milliseconds

}
