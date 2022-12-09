#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int echoPin = A1; // Echo Pin
int trigPin = A2; // Trigger Pin

int count = 0; // How mamy cups have been collected
long duration; // Duration used to calculate distance
long distance; // Distance in cm

void setup() {

  lcd.init();
  lcd.backlight();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {

  lcd.setCursor(0,1);
  lcd.print("Target = 540.000");
  lcd.setCursor(0,0);
  lcd.print("Cups:");
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;

  if (distance > 5.0) {
   
      count++;

      Serial.println(count);
     
      delay(50); // Waits 50 milliseconds
     
  }

  lcd.setCursor(5,0);
  lcd.print(count);
  delay(200);  // Waits 5 milliseconds
  lcd.clear(); 
  

}
